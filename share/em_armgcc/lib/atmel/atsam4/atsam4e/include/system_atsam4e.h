#ifndef _08AB70F7_C5C3_4B2C_90E6_CF171F6B2DB5_
#define _08AB70F7_C5C3_4B2C_90E6_CF171F6B2DB5_

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

#endif /* _08AB70F7_C5C3_4B2C_90E6_CF171F6B2DB5_ */
