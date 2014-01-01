#ifndef _C6FDECD0_4C31_4140_A431_5B278717A71C_
#define _C6FDECD0_4C31_4140_A431_5B278717A71C_

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

#endif /* _C6FDECD0_4C31_4140_A431_5B278717A71C_ */
