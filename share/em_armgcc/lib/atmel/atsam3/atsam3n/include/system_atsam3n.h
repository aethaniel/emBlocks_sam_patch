#ifndef _EF4986E3_D16B_4BC9_95A8_625E82525C89_
#define _EF4986E3_D16B_4BC9_95A8_625E82525C89_

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

#endif /* _EF4986E3_D16B_4BC9_95A8_625E82525C89_ */
