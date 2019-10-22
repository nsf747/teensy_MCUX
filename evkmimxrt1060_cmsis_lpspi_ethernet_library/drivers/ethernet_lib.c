/*
 * ethernet_lib.c
 *
 *  Created on: 01-Oct-2019
 *      Author: SADHANA-PC
 */
#include "ethernet_lib.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_lpspi_cmsis.h"
#include "board.h"

#include "fsl_common.h"
#include "pin_mux.h"
#if ((defined FSL_FEATURE_SOC_INTMUX_COUNT) && (FSL_FEATURE_SOC_INTMUX_COUNT))
#include "fsl_intmux.h"
#endif

uint8_t i=0;
uint8_t masterRxData[TRANSFER_SIZE] = {0U};
uint8_t masterTxData[TRANSFER_SIZE] = {0U};

volatile bool isTransferCompleted = false;
volatile bool isMasterOnTransmit  = false;
volatile bool isMasterOnReceive   = false;

uint32_t LPSPI4_GetFreq(void)
{
    return EXAMPLE_LPSPI_CLOCK_FREQ;
}

void _delay_ms(unsigned int delay)
{
	int count;
	for (count = 0; count < EXAMPLE_LPSPI_DEALY_COUNT*delay; count++)
	        {
	            __NOP();
	        }
}
void LPSPI_MasterSignalEvent_t(uint32_t event)
{
    if (true == isMasterOnReceive)
    {
       // PRINTF("This is LPSPI_MasterSignalEvent_t\r\n");
       // PRINTF("Master receive data from slave has completed!\r\n");
        isMasterOnReceive = false;
    }
    if (true == isMasterOnTransmit)
    {
        //PRINTF("This is LPSPI_MasterSignalEvent_t\r\n");
        //PRINTF("Master transmit data to slave has completed!\r\n");
        isMasterOnTransmit = false;
    }
    isTransferCompleted = true;
}

void SPI_Write(uint16_t addr,uint8_t data)
{
  // Activate the CS pin
  // Start Wiznet W5100 Write OpCode transmission
	masterTxData[0]=WIZNET_WRITE_OPCODE;
  // Wait for transmission complete
  //while();
  // Start Wiznet W5100 Address High Bytes transmission
	masterTxData[1]= (addr & 0xFF00) >> 8;
  // Wait for transmission complete
  //while();
  // Start Wiznet W5100 Address Low Bytes transmission
	masterTxData[2] = addr & 0x00FF;
  // Wait for transmission complete
  //while();

  // Start Data transmission
	masterTxData[3] = data;
  // Wait for transmission complete
	//PRINTF("Data frame %.2x%.2x%.2x%.2x\n",masterTxData[0],masterTxData[1],masterTxData[2],masterTxData[3]);
	isTransferCompleted = false;
	isMasterOnTransmit  = true;
	/* Start master transfer, send data to slave */
	DRIVER_MASTER_SPI.Transfer(masterTxData,masterRxData, TRANSFER_SIZE);
	/* Wait transfer complete */
	while (!isTransferCompleted);
	isTransferCompleted = false;
	isMasterOnReceive   = true;
	_delay_ms(1);
	for (i=0;i<4;i++)
	masterRxData[i] = 0U;
/* Start master transfer, receive data from slave */
	/*DRIVER_MASTER_SPI.Receive(masterRxData, 4U);

	while (!isTransferCompleted)
	{
	}*/
	//PRINTF(" Received Data %.2x%.2x%.2x%.2x\n",masterRxData[0],masterRxData[1],masterRxData[2],masterRxData[3]);
}
unsigned char SPI_Read(uint16_t addr)
{
	// Activate the CS pin
	// Start Wiznet W5100 Write OpCode transmission
		masterTxData[0]=WIZNET_READ_OPCODE;
	// Wait for transmission complete
	//while();
	// Start Wiznet W5100 Address High Bytes transmission
		masterTxData[1]= (addr & 0xFF00) >> 8;
	// Wait for transmission complete
	//while();
	// Start Wiznet W5100 Address Low Bytes transmission
		masterTxData[2] = addr & 0x00FF;

	// Send Dummy transmission for reading the data
		masterTxData[3] = 0x00;

		isTransferCompleted = false;
		isMasterOnReceive   = true;

		/*DRIVER_MASTER_SPI.Receive(masterRxData, 4U);
		while (!isTransferCompleted)
		{
		}*/
		/* Start master transfer, send data to slave */
		//PRINTF("Clear FIFO value %.2x%.2x%.2x%.2x\n",masterRxData[0],masterRxData[1],masterRxData[2],masterRxData[3]);
		for (i=0;i<4;i++)
			masterRxData[i] = 0U;
		isTransferCompleted = false;
		isMasterOnTransmit   = true;
		//PRINTF("Send read Addr %.2x%.2x%.2x%.2x\n",masterTxData[0],masterTxData[1],masterTxData[2],masterTxData[3]);
		DRIVER_MASTER_SPI.Transfer(masterTxData,masterRxData, TRANSFER_SIZE);
		/* Wait transfer complete */
		while (!isTransferCompleted)
		{
		}
		isTransferCompleted = false;
		isMasterOnReceive   = true;
	/* Start master transfer, receive data from slave */
		/*DRIVER_MASTER_SPI.Receive(masterRxData, 4U);

		while (!isTransferCompleted)
		{
		}*/
		//PRINTF("Read FIFO %.2x%.2x%.2x%.2x\n",masterRxData[0],masterRxData[1],masterRxData[2],masterRxData[3]);
  return masterRxData[3];
}

void W5100_Init(void)
{
  // Ethernet Setup
  unsigned char mac_addr[] = {0x00,0x16,0x36,0xDE,0x58,0xF6};
  unsigned char ip_addr[] = {192,168,1,10};
  unsigned char sub_mask[] = {255,255,255,0};
  unsigned char gtw_addr[] = {192,168,1,1};
  // Setting the Wiznet W5100 Mode Register: 0x0000
  SPI_Write(MR,0x80);            // MR = 0b10000000;
  _delay_ms(10);
  PRINTF("Reading MR: %d\n",SPI_Read(MR));
  // Setting the Wiznet W5100 Gateway Address (GAR): 0x0001 to 0x0004
  PRINTF("Setting GAR: %d.%d.%d.%d\n",gtw_addr[0],gtw_addr[1],\
          gtw_addr[2],gtw_addr[3]);
  SPI_Write(GAR + 0,gtw_addr[0]);
  SPI_Write(GAR + 1,gtw_addr[1]);
  SPI_Write(GAR + 2,gtw_addr[2]);
  SPI_Write(GAR + 3,gtw_addr[3]);
  _delay_ms(10);
  PRINTF("Reading GAR: %d.%d.%d.%d\n",SPI_Read(GAR + 0),SPI_Read(GAR + 1),\
          SPI_Read(GAR + 2),SPI_Read(GAR + 3));
  // Setting the Wiznet W5100 Source Address Register (SAR): 0x0009 to 0x000E
  PRINTF("Setting SAR: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",mac_addr[0],mac_addr[1],\
          mac_addr[2],mac_addr[3],mac_addr[4],mac_addr[5]);
  SPI_Write(SAR + 0,mac_addr[0]);
  SPI_Write(SAR + 1,mac_addr[1]);
  SPI_Write(SAR + 2,mac_addr[2]);
  SPI_Write(SAR + 3,mac_addr[3]);
  SPI_Write(SAR + 4,mac_addr[4]);
  SPI_Write(SAR + 5,mac_addr[5]);
  _delay_ms(10);
  PRINTF("Reading SAR: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",SPI_Read(SAR + 0),SPI_Read(SAR + 1),\
          SPI_Read(SAR + 2),SPI_Read(SAR + 3),SPI_Read(SAR + 4),SPI_Read(SAR + 5));
  // Setting the Wiznet W5100 Sub Mask Address (SUBR): 0x0005 to 0x0008
  PRINTF("Setting SUBR: %d.%d.%d.%d\n",sub_mask[0],sub_mask[1],\
          sub_mask[2],sub_mask[3]);
  SPI_Write(SUBR + 0,sub_mask[0]);
  SPI_Write(SUBR + 1,sub_mask[1]);
  SPI_Write(SUBR + 2,sub_mask[2]);
  SPI_Write(SUBR + 3,sub_mask[3]);
  _delay_ms(10);
  PRINTF("Reading SUBR: %d.%d.%d.%d\n",SPI_Read(SUBR + 0),SPI_Read(SUBR + 1),\
          SPI_Read(SUBR + 2),SPI_Read(SUBR + 3));
  // Setting the Wiznet W5100 IP Address (SIPR): 0x000F to 0x0012
  PRINTF("Setting SIPR: %d.%d.%d.%d\n",ip_addr[0],ip_addr[1],\
          ip_addr[2],ip_addr[3]);
  SPI_Write(SIPR + 0,ip_addr[0]);
  SPI_Write(SIPR + 1,ip_addr[1]);
  SPI_Write(SIPR + 2,ip_addr[2]);
  SPI_Write(SIPR + 3,ip_addr[3]);
  _delay_ms(10);
  PRINTF("Reading SIPR: %d.%d.%d.%d\n",SPI_Read(SIPR + 0),SPI_Read(SIPR + 1),\
          SPI_Read(SIPR + 2),SPI_Read(SIPR + 3));

  // Setting the Wiznet W5100 RX and TX Memory Size, we use 2KB for Rx/Tx 4 channels
  PRINTF("Setting Wiznet RMSR and TMSR\n\n");
  SPI_Write(RMSR,0x55);
  SPI_Write(TMSR,0x55);
  PRINTF("Done Wiznet W5100 Initialized!\n");
}

