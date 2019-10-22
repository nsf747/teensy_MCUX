/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */



/*******************************************************************************
 * Code
 ******************************************************************************/
//#include "ethernet_lib.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_lpspi_cmsis.h"
#include "board.h"

#include "fsl_common.h"
#include "pin_mux.h"
#if ((defined FSL_FEATURE_SOC_INTMUX_COUNT) && (FSL_FEATURE_SOC_INTMUX_COUNT))
#include "fsl_intmux.h"
#endif

#include "fsl_qtmr.h"
#include"Wiznet_Ethernet_Library/Ethernet/wizchip_conf.h"
#include"Wiznet_Ethernet_Library/Ethernet/socket.h"
#include "Wiznet_Ethernet_Library/Internet/DHCP/dhcp.h"

#define BOARD_QTMR_BASEADDR TMR3
#define BOARD_FIRST_QTMR_CHANNEL kQTMR_Channel_0
#define BOARD_SECOND_QTMR_CHANNEL kQTMR_Channel_1
#define QTMR_ClockCounterOutput kQTMR_ClockCounter0Output

/* Interrupt number and interrupt handler for the QTMR instance used */
#define QTMR_IRQ_ID TMR3_IRQn
#define QTMR_IRQ_HANDLER TMR3_IRQHandler

/* Get source clock for QTMR driver */
#define QTMR_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_IpgClk)

uint8_t i=0,sock=1;
uint8_t masterRxData[TRANSFER_SIZE] = {0U};
uint8_t masterTxData[TRANSFER_SIZE] = {0U};
uint8_t recMAC[10]={0};


volatile bool qtmrIsrFlag = false;
unsigned int loop_counter=0;
uint8_t messagebuf[2048]={0},ipaddr[4]={0};
qtmr_config_t qtmrConfig;
wiz_NetInfo net_info = { .mac 	= {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},
                         .ip 	= {192, 168, 1, 37},
                         .sn 	= {255, 255, 255, 0},
                         .gw 	= {192, 168, 1, 1},
                         .dns = {8, 8, 8, 8},
                         .dhcp = NETINFO_DHCP };

void dhcp_timer_enable(void)
{
	PRINTF("\r\n****Chain Timer use-case, 10 second tick.****\n");
	QTMR_GetDefaultConfig(&qtmrConfig);
   /* Init the first channel to use the IP Bus clock div by 128 */
   qtmrConfig.primarySource = kQTMR_ClockDivide_128;
   QTMR_Init(BOARD_QTMR_BASEADDR, BOARD_FIRST_QTMR_CHANNEL, &qtmrConfig);

   /* Init the second channel to use output of the first channel as we are chaining the first channel and the second
    * channel */
   qtmrConfig.primarySource = QTMR_ClockCounterOutput;
   QTMR_Init(BOARD_QTMR_BASEADDR, BOARD_SECOND_QTMR_CHANNEL, &qtmrConfig);

   /* Set the first channel period to be 1 millisecond */
   QTMR_SetTimerPeriod(BOARD_QTMR_BASEADDR, BOARD_FIRST_QTMR_CHANNEL, MSEC_TO_COUNT(1U, (QTMR_SOURCE_CLOCK / 128)));

   /* Set the second channel count which increases every millisecond, set compare event for 10 second */
   QTMR_SetTimerPeriod(BOARD_QTMR_BASEADDR, BOARD_SECOND_QTMR_CHANNEL, 1000);

   /* Enable the second channel compare interrupt */
   QTMR_EnableInterrupts(BOARD_QTMR_BASEADDR, BOARD_SECOND_QTMR_CHANNEL, kQTMR_CompareInterruptEnable);

   /* Start the second channel in cascase mode, chained to the first channel as set earlier via the primary source
    * selection */
   QTMR_StartTimer(BOARD_QTMR_BASEADDR, BOARD_SECOND_QTMR_CHANNEL, kQTMR_CascadeCount);

   /* Start the first channel to count on rising edge of the primary source clock */
   QTMR_StartTimer(BOARD_QTMR_BASEADDR, BOARD_FIRST_QTMR_CHANNEL, kQTMR_PriSrcRiseEdge);
}

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

void QTMR_IRQ_HANDLER(void)
{
    /* Clear interrupt flag.*/
    QTMR_ClearStatusFlags(BOARD_QTMR_BASEADDR, BOARD_SECOND_QTMR_CHANNEL, kQTMR_CompareFlag);

    DHCP_time_handler();
/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

int main(void)
{
	//unsigned int loop_counter=0;
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /*Set clock source for LPSPI*/

    PRINTF("LPSPI CMSIS driver board to board interrupt example.\r\n");
    PRINTF("This example use one board as master and another as slave.\r\n");
    PRINTF("Master and slave uses interrupt way. Slave should start first. \r\n");
    PRINTF("Please make sure you make the correct line connection. Basically, the connection is: \r\n");
    PRINTF("LPSPI_master -- LPSPI_slave   \r\n");
    PRINTF("   CLK       --    CLK  \r\n");
    PRINTF("   PCS       --    PCS \r\n");
    PRINTF("   SOUT      --    SIN  \r\n");
    PRINTF("   SIN       --    SOUT \r\n");
    PRINTF("   GND       --    GND \r\n");

    /*uint32_t errorCount;
    uint32_t loopCount = 1;
    uint32_t i;*/
    GPIO_PinWrite(GPIO2, 00U, 1U);
    /*LPSPI master init*/
    DRIVER_MASTER_SPI.Initialize(LPSPI_MasterSignalEvent_t);
    DRIVER_MASTER_SPI.PowerControl(ARM_POWER_FULL);
    DRIVER_MASTER_SPI.Control(ARM_SPI_MODE_MASTER, TRANSFER_BAUDRATE);
    PRINTF("%d",wizchip_init(NULL,NULL));
    // register chip select and SPI callback functions
        reg_wizchip_cs_cbfunc(NULL,NULL);
        reg_wizchip_spi_cbfunc(NULL,NULL);
        _delay_ms(100);
    PRINTF("Wizchip init\n");
        // initialise W5500
        PRINTF("%d\n",wizchip_init(NULL, NULL));
            /*masterTxData[0]=0xf0;
            masterTxData[1]=0x00;

            	masterTxData[2]=0x00;
            	masterTxData[3]=0x80;
            	setintflags();
            	GPIO_PinWrite(GPIO2, 00U, 0U);
            	DRIVER_MASTER_SPI.Transfer(masterTxData,masterRxData, 4U );
            	waitfortransfer();
            	GPIO_PinWrite(GPIO2, 00U, 1U);*/

        PRINTF("Wizchip set info\n");
        wizchip_setnetinfo(&net_info);
        //PRINTF("Reading SAR: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n\n",recMAC[0],recMAC[1],recMAC[2],recMAC[3],recMAC[4],recMAC[5]);
        //_delay_ms(100);
        // initialise DHCP on socket 0
        dhcp_timer_enable();
        PRINTF("DHCP Init\n");
        DHCP_init(0, messagebuf);
        PRINTF("DHCP Run\n");
        _delay_ms(250);



    while (1)
    {
    	loop_counter++;
    	PRINTF("%d\n\n",loop_counter);
    	switch (DHCP_run()) {
    	                case DHCP_IP_ASSIGN:
    	                    PRINTF("IP assigned\n");
    	                    getIPfromDHCP(ipaddr);
    	                    PRINTF("%d.%d.%d.%d\n",ipaddr[0],ipaddr[1],ipaddr[2],ipaddr[3]);

    	                    break;
    	                case DHCP_IP_CHANGED:
    	                	PRINTF("IP changed\n");
    	                    break;
    	                case DHCP_IP_LEASED:
    	                    PRINTF("IP Leased");
    	                    getIPfromDHCP(ipaddr);
    	                    PRINTF("%d.%d.%d.%d\n",ipaddr[0],ipaddr[1],ipaddr[2],ipaddr[3]);
    	                    break;
    	                case DHCP_FAILED:
    	                	PRINTF("DHCP failed\n");
    	                    break;
    	                default:
    	                	PRINTF("DHCP unknown\n");
    	                    break;
    	            }
    	_delay_ms(100);
    }
}
