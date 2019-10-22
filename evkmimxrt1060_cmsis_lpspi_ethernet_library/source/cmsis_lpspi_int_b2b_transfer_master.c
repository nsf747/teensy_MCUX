/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */



/*******************************************************************************
 * Code
 ******************************************************************************/
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

int main(void)
{
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

    /*LPSPI master init*/
   DRIVER_MASTER_SPI.Initialize(LPSPI_MasterSignalEvent_t);
   DRIVER_MASTER_SPI.PowerControl(ARM_POWER_FULL);
   DRIVER_MASTER_SPI.Control(ARM_SPI_MODE_MASTER, TRANSFER_BAUDRATE);
    GPIO_PinWrite(GPIO2, 11U, 0U);
    _delay_ms(50);
    //GPIO_PinWrite(GPIO2, 11U, 1U);
    _delay_ms(250);
    W5100_Init();

    while (1)
    {

        /* Set up the transfer data */
      /*  for (i = 0U; i < TRANSFER_SIZE; i++)
        {
            masterTxData[i] = (i + loopCount) % 256U;
            masterRxData[i] = 0U;
        }*/

        /* Print out transmit buffer */
        /*PRINTF("\r\n Master transmit:\r\n");
        for (i = 0U; i < TRANSFER_SIZE; i++)
        {*/
            /* Print 16 numbers in a line */
            /*if ((i & 0x0FU) == 0U)
            {
                PRINTF("\r\n");
            }
            PRINTF(" %02X", masterTxData[i]);
        }
        PRINTF("\r\n");

        isTransferCompleted = false;
        isMasterOnTransmit  = true;*/
        /* Start master transfer, send data to slave */
        //DRIVER_MASTER_SPI.Send(masterTxData, TRANSFER_SIZE);
        /* Wait transfer complete */
        /*while (!isTransferCompleted)
        {
        }*/

        /* Delay to wait slave is ready */
        /*for (i = 0; i < EXAMPLE_LPSPI_DEALY_COUNT; i++)
        {
            __NOP();
        }

        isTransferCompleted = false;
        isMasterOnReceive   = true;*/
        /* Start master transfer, receive data from slave */
        /*DRIVER_MASTER_SPI.Receive(masterRxData, TRANSFER_SIZE);

        while (!isTransferCompleted)
        {
        }

        errorCount = 0U;
        for (i = 0U; i < TRANSFER_SIZE; i++)
        {
            if (masterTxData[i] != masterRxData[i])
            {
                errorCount++;
            }
        }
        if (errorCount == 0U)
        {
            PRINTF(" \r\nLPSPI transfer all data matched! \r\n");*/
            /* Print out receive buffer */
            /*PRINTF("\r\n Master received:\r\n");
            for (i = 0U; i < TRANSFER_SIZE; i++)
            {*/
                /* Print 16 numbers in a line */
                /*if ((i & 0x0FU) == 0U)
                {
                    PRINTF("\r\n");
                }
                PRINTF(" %02X", masterRxData[i]);
            }
            PRINTF("\r\n");
        }
        else
        {
            PRINTF(" \r\nError occurred in LPSPI transfer ! \r\n");
        }*/

        /* Wait for press any key */
        /*PRINTF("\r\n Input any char to run again\r\n");
        GETCHAR();*/

        /* Increase loop count to change transmit buffer */
        //loopCount++;
    }
}
