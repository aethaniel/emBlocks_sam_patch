#ifndef _DB26965E_836F_4DD0_A7FA_052870BAEA37_
#define _DB26965E_836F_4DD0_A7FA_052870BAEA37_

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

#endif /* _DB26965E_836F_4DD0_A7FA_052870BAEA37_ */
