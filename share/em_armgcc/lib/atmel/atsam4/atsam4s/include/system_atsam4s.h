#ifndef _E0F9F3FA_4017_445C_8C15_B947B56B467F_
#define _E0F9F3FA_4017_445C_8C15_B947B56B467F_

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

#endif /* _E0F9F3FA_4017_445C_8C15_B947B56B467F_ */
