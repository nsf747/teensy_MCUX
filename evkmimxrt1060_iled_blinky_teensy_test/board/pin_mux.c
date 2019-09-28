/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v6.0
processor: MIMXRT1062xxxxA
package_id: MIMXRT1062DVL6A
mcu_data: ksdk2_0
processor_version: 6.0.1
board: MIMXRT1060-EVK
pin_labels:
- {pin_num: F14, pin_signal: GPIO_AD_B0_09, label: 'JTAG_TDI/J21[5]/ENET_RST/J22[5]/USER_LED', identifier: USER_LED}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: F14, peripheral: JTAG, signal: TDI, pin_signal: GPIO_AD_B0_09, identifier: ''}
  - {pin_num: D8, peripheral: GPIO2, signal: 'gpio_io, 03', pin_signal: GPIO_B0_03, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: K14, peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_12}
  - {pin_num: L14, peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_13}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           /* iomuxc clock (iomuxc_clk_enable): 0x03U */

  /* GPIO configuration of LCDIF_VSYNC on GPIO_B0_03 (pin D8) */
  gpio_pin_config_t LCDIF_VSYNC_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 1U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_B0_03 (pin D8) */
  GPIO_PinInit(GPIO2, 3U, &LCDIF_VSYNC_config);

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_09_JTAG_TDI,          /* GPIO_AD_B0_09 is configured as JTAG_TDI */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_12_LPUART1_TX,        /* GPIO_AD_B0_12 is configured as LPUART1_TX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_13_LPUART1_RX,        /* GPIO_AD_B0_13 is configured as LPUART1_RX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_B0_03_GPIO2_IO03,           /* GPIO_B0_03 is configured as GPIO2_IO03 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_GPR->GPR27 = ((IOMUXC_GPR->GPR27 &
    (~(IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_MASK))) /* Mask bits to zero which are setting */
      | IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL(0x00U) /* GPIO2 and GPIO7 share same IO MUX function, GPIO_MUX2 selects one GPIO function: 0x00U */
    );
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/