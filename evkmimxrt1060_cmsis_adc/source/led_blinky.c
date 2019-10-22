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
#include <string.h>
#include "fsl_adc.h"

#include "pin_mux.h"
#include "system_MIMXRT1062.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_LED_GPIO GPIO2
#define EXAMPLE_LED_GPIO_PIN 3U
#define EXAMPLE_DELAY_COUNT 60000000
#define DEMO_ADC_BASE ADC1
#define DEMO_ADC_USER_CHANNEL 7U
#define DEMO_ADC_CHANNEL_GROUP 0U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint32_t g_systickCounter;
/* The PIN status */
volatile bool g_pinSet = false;
const uint32_t g_Adc_12bitFullRange = 4096U;

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
    adc_config_t adcConfigStrcut;
    adc_channel_config_t adcChannelConfigStruct;

    /* Init output LED GPIO. */
    //GPIO_PinInit(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, &led_config);
    PRINTF("hello world.\r\n");
    GPIO_PinWrite(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, 0U);
    g_pinSet = true;
    ADC_GetDefaultConfig(&adcConfigStrcut);
    ADC_Init(DEMO_ADC_BASE, &adcConfigStrcut);
    /* Set systick reload value to generate 1ms interrupt */

    #if !(defined(FSL_FEATURE_ADC_SUPPORT_HARDWARE_TRIGGER_REMOVE) && FSL_FEATURE_ADC_SUPPORT_HARDWARE_TRIGGER_REMOVE)
    ADC_EnableHardwareTrigger(DEMO_ADC_BASE, false);
#endif
    /* Do auto hardware calibration. */
       if (kStatus_Success == ADC_DoAutoCalibration(DEMO_ADC_BASE))
       {
           PRINTF("ADC_DoAntoCalibration() Done.\r\n");
       }
       else
       {
           PRINTF("ADC_DoAutoCalibration() Failed.\r\n");
       }

       /* Configure the user channel and interrupt. */
       adcChannelConfigStruct.channelNumber                        = DEMO_ADC_USER_CHANNEL;
       adcChannelConfigStruct.enableInterruptOnConversionCompleted = false;

       PRINTF("ADC Full Range: %d\r\n", g_Adc_12bitFullRange);

    while (1)
    {
        /* Delay 1000 ms */
        SysTick_DelayTicks(1000U);
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
        ADC_SetChannelConfig(DEMO_ADC_BASE, DEMO_ADC_CHANNEL_GROUP, &adcChannelConfigStruct);
		while (0U == ADC_GetChannelStatusFlags(DEMO_ADC_BASE, DEMO_ADC_CHANNEL_GROUP))
		{
		}
		PRINTF("ADC Value: %d\r\n", ADC_GetChannelConversionValue(DEMO_ADC_BASE, DEMO_ADC_CHANNEL_GROUP));
    }
}
