#ifndef _25D3F181_2F3C_4456_8F8D_7938ABEC9EBC_
#define _25D3F181_2F3C_4456_8F8D_7938ABEC9EBC_

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

#endif /* _25D3F181_2F3C_4456_8F8D_7938ABEC9EBC_ */
