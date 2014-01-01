#ifndef _D82EA4CD_C8BE_4493_A825_FD346EC72780_
#define _D82EA4CD_C8BE_4493_A825_FD346EC72780_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern uint32_t SystemCoreClock; /* System Clock Frequency (Core Clock) */

/**
 * @brief Setup the microcontroller system.
 * Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit(void);

/**
 * @brief Updates the SystemCoreClock with current core Clock
 * retrieved from cpu registers.
 */
void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /* _D82EA4CD_C8BE_4493_A825_FD346EC72780_ */
