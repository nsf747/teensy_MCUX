/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"
#include "fsl_gpio.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "system_MIMXRT1062.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_LED_GPIO GPIO2
#define EXAMPLE_LED_GPIO_PIN 3U
#define EXAMPLE_DELAY_COUNT 16000000

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint32_t g_systickCounter;
/* The PIN status */
volatile bool g_pinSet = false;

/*******************************************************************************
 * Code
 ******************************************************************************/


void SysTick_DelayTicks(uint32_t n)
{
	volatile uint32_t i = 0;
	    for (i = 0; i < EXAMPLE_DELAY_COUNT; ++i)
	    {
	        __asm("NOP"); /* delay */
	    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Define the init structure for the output LED pin*/
    //gpio_pin_config_t led_config = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};

    /* Board pin init */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    /* Update the core clock */
    SystemCoreClockUpdate();

    /* Init output LED GPIO. */
    //GPIO_PinInit(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, &led_config);
    PRINTF("hello world.\r\n");
    GPIO_PinWrite(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, 0U);
    g_pinSet = true;
    /* Set systick reload value to generate 1ms interrupt */

    while (1)
    {
        /* Delay 1000 ms */
        SysTick_DelayTicks(10000000U);
        if (g_pinSet)
        {
            GPIO_PinWrite(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, 0U);
            g_pinSet = false;
            PRINTF("0\r\n");
        }
        else
        {
            GPIO_PinWrite(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, 1U);
            g_pinSet = true;
            PRINTF("1\r\n");
        }
    }
}
