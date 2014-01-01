#include "atsam.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t SystemCoreClock = CHIP_FREQ_MAINCK_RC_4MHZ;

/**
 * \brief Setup the microcontroller system.
 * Initialize the System and update the SystemFrequency variable.
 */
void SystemInit( void )
{
}

void SystemCoreClockUpdate( void )
{
}

#ifdef __cplusplus
}
#endif

