#ifndef _6EDEAE7D_6C71_48AE_90F2_2808E4E34967_
#define _6EDEAE7D_6C71_48AE_90F2_2808E4E34967_

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

#endif /* _6EDEAE7D_6C71_48AE_90F2_2808E4E34967_ */
