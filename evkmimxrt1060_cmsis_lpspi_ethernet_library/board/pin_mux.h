/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_AD_B0_13 (coord L14), UART1_RXD */
#define BOARD_INITPINS_UART1_RXD_PERIPHERAL                              LPUART1   /*!< Device name: LPUART1 */
#define BOARD_INITPINS_UART1_RXD_SIGNAL                                       RX   /*!< LPUART1 signal: RX */

/* GPIO_AD_B0_12 (coord K14), UART1_TXD */
#define BOARD_INITPINS_UART1_TXD_PERIPHERAL                              LPUART1   /*!< Device name: LPUART1 */
#define BOARD_INITPINS_UART1_TXD_SIGNAL                                       TX   /*!< LPUART1 signal: TX */

/* GPIO_B0_03 (coord D8), LCDIF_VSYNC */
#define BOARD_INITPINS_LCDIF_VSYNC_PERIPHERAL                             LPSPI4   /*!< Device name: LPSPI4 */
#define BOARD_INITPINS_LCDIF_VSYNC_SIGNAL                                    SCK   /*!< LPSPI4 signal: SCK */

/* GPIO_B0_02 (coord E8), LCDIF_HSYNC */
#define BOARD_INITPINS_LCDIF_HSYNC_PERIPHERAL                             LPSPI4   /*!< Device name: LPSPI4 */
#define BOARD_INITPINS_LCDIF_HSYNC_SIGNAL                                    SDO   /*!< LPSPI4 signal: SDO */

/* GPIO_B0_01 (coord E7), LCDIF_ENABLE */
#define BOARD_INITPINS_LCDIF_ENABLE_PERIPHERAL                            LPSPI4   /*!< Device name: LPSPI4 */
#define BOARD_INITPINS_LCDIF_ENABLE_SIGNAL                                   SDI   /*!< LPSPI4 signal: SDI */

/* GPIO_B0_00 (coord D7), LCDIF_CLK */
#define BOARD_INITPINS_LCDIF_CLK_PERIPHERAL                               LPSPI4   /*!< Device name: LPSPI4 */
#define BOARD_INITPINS_LCDIF_CLK_SIGNAL                                     PCS0   /*!< LPSPI4 signal: PCS0 */

/* GPIO_B0_11 (coord A10), LCDIF_D7/BT_CFG[7] */
#define BOARD_INITPINS_LCDIF_D7_GPIO                                       GPIO2   /*!< GPIO device name: GPIO2 */
#define BOARD_INITPINS_LCDIF_D7_PORT                                       GPIO2   /*!< PORT device name: GPIO2 */
#define BOARD_INITPINS_LCDIF_D7_PIN                                          11U   /*!< GPIO2 pin index: 11 */

/* GPIO_AD_B1_06 (coord J12), CSI_VSYNC/J35[18]/J22[2]/UART_TX */
#define BOARD_INITPINS_CSI_VSYNC_GPIO                                      GPIO1   /*!< GPIO device name: GPIO1 */
#define BOARD_INITPINS_CSI_VSYNC_PORT                                      GPIO1   /*!< PORT device name: GPIO1 */
#define BOARD_INITPINS_CSI_VSYNC_PIN                                         22U   /*!< GPIO1 pin index: 22 */

/* GPIO_B0_10 (coord D9), LCDIF_D6/BT_CFG[6] */
#define BOARD_INITPINS_LCDIF_D6_GPIO                                       GPIO2   /*!< GPIO device name: GPIO2 */
#define BOARD_INITPINS_LCDIF_D6_PORT                                       GPIO2   /*!< PORT device name: GPIO2 */
#define BOARD_INITPINS_LCDIF_D6_PIN                                          10U   /*!< GPIO2 pin index: 10 */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void LPSPI4_InitPins(void);


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void LPSPI4_DeinitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
