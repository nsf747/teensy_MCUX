/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_common.h"
#include "fsl_lpuart.h"
#include "fsl_clock.h"
#include "fsl_lpspi.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* Definition of peripheral ID */
#define LPUART_1_PERIPHERAL LPUART1
/* Definition of the clock source frequency */
#define LPUART_1_CLOCK_SOURCE 80000000UL
/* BOARD_InitPeripherals defines for LPSPI4 */
/* Definition of peripheral ID */
#define LPSPI_4_PERIPHERAL LPSPI4
/* Definition of clock source */
#define LPSPI_4_CLOCK_FREQ 8000000UL

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern const lpuart_config_t LPUART_1_config;
extern const lpspi_master_config_t LPSPI_4_config;

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
