#ifndef _E4A39CFE_1D84_459B_B9D4_81FF105E9646_
#define _E4A39CFE_1D84_459B_B9D4_81FF105E9646_

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

#endif /* _E4A39CFE_1D84_459B_B9D4_81FF105E9646_ */
