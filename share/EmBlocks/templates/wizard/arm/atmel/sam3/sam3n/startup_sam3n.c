#include "atsam.h"

/* Header for end of stack, declared in linker file */
extern uint32_t _estack;

/* For Reset handler, see main.c */

/* Default empty handler, see main.c */
void Dummy_Handler(void);

/* Cortex-M3 core handlers */
void NMI_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void HardFault_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void MemManage_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void BusFault_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UsageFault_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SVC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DebugMon_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PendSV_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SysTick_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

/* Peripherals handlers */
void SUPC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RSTC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTT_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void WDT_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PMC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EFC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART0_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART1_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOA_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOB_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3N_PIOC_INSTANCE_
void PIOC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3N_PIOC_INSTANCE_ */
void USART0_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3N_USART1_INSTANCE_
void USART1_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3N_USART1_INSTANCE_ */
void TWI0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC4_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC5_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DACC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

/* Exception Table */
__attribute__ ((section(".vectors")))
const DeviceVectors exception_table =
{
	/* Configure Initial Stack Pointer, using linker-generated symbols */
	.pvStack = (void*) (&_estack),

	.pfnReset_Handler      = (void*) Reset_Handler,
	.pfnNMI_Handler        = (void*) NMI_Handler,
	.pfnHardFault_Handler  = (void*) HardFault_Handler,
	.pfnMemManage_Handler  = (void*) MemManage_Handler,
	.pfnBusFault_Handler   = (void*) BusFault_Handler,
	.pfnUsageFault_Handler = (void*) UsageFault_Handler,
	.pfnReserved1_Handler  = (void*) (0UL),          /* Reserved */
	.pfnReserved2_Handler  = (void*) (0UL),          /* Reserved */
	.pfnReserved3_Handler  = (void*) (0UL),          /* Reserved */
	.pfnReserved4_Handler  = (void*) (0UL),          /* Reserved */
	.pfnSVC_Handler        = (void*) SVC_Handler,
	.pfnDebugMon_Handler   = (void*) DebugMon_Handler,
	.pfnReserved5_Handler  = (void*) (0UL),          /* Reserved */
	.pfnPendSV_Handler     = (void*) PendSV_Handler,
	.pfnSysTick_Handler    = (void*) SysTick_Handler,

	/* Configurable interrupts */
	.pfnSUPC_Handler   = (void*) SUPC_Handler,   /* 0  Supply Controller */
	.pfnRSTC_Handler   = (void*) RSTC_Handler,   /* 1  Reset Controller */
	.pfnRTC_Handler    = (void*) RTC_Handler,    /* 2  Real Time Clock */
	.pfnRTT_Handler    = (void*) RTT_Handler,    /* 3  Real Time Timer */
	.pfnWDT_Handler    = (void*) WDT_Handler,    /* 4  Watchdog Timer */
	.pfnPMC_Handler    = (void*) PMC_Handler,    /* 5  Power Management Controller */
	.pfnEFC_Handler    = (void*) EFC_Handler,    /* 6  Enhanced Flash Controller */
	.pvReserved7       = (void*) (0UL),          /* 7  Reserved */
	.pfnUART0_Handler  = (void*) UART0_Handler,  /* 8  UART 0 */
	.pfnUART1_Handler  = (void*) UART1_Handler,  /* 9  UART 1 */
	.pvReserved10      = (void*) (0UL),          /* 10 Reserved */
	.pfnPIOA_Handler   = (void*) PIOA_Handler,   /* 11 Parallel I/O Controller A */
	.pfnPIOB_Handler   = (void*) PIOB_Handler,   /* 12 Parallel I/O Controller B */
#ifdef _SAM3N_PIOC_INSTANCE_
	.pfnPIOC_Handler   = (void*) PIOC_Handler,   /* 13 Parallel I/O Controller C */
#else
	.pvReserved13      = (void*) (0UL),          /* 13 Reserved */
#endif /* _SAM3N_PIOC_INSTANCE_ */
	.pfnUSART0_Handler = (void*) USART0_Handler, /* 14 USART 0 */
#ifdef _SAM3N_USART1_INSTANCE_
	.pfnUSART1_Handler = (void*) USART1_Handler, /* 15 USART 1 */
#else
	.pvReserved15      = (void*) (0UL),          /* 15 Reserved */
#endif /* _SAM3N_USART1_INSTANCE_ */
	.pvReserved16      = (void*) (0UL),          /* 16 Reserved */
	.pvReserved17      = (void*) (0UL),          /* 17 Reserved */
	.pvReserved18      = (void*) (0UL),          /* 18 Reserved */
	.pfnTWI0_Handler   = (void*) TWI0_Handler,   /* 19 Two Wire Interface 0 */
	.pfnTWI1_Handler   = (void*) TWI1_Handler,   /* 20 Two Wire Interface 1 */
	.pfnSPI_Handler    = (void*) SPI_Handler,    /* 21 Serial Peripheral Interface */
	.pvReserved22      = (void*) (0UL),          /* 22 Reserved */
	.pfnTC0_Handler    = (void*) TC0_Handler,    /* 23 Timer/Counter 0 */
	.pfnTC1_Handler    = (void*) TC1_Handler,    /* 24 Timer/Counter 1 */
	.pfnTC2_Handler    = (void*) TC2_Handler,    /* 25 Timer/Counter 2 */
	.pfnTC3_Handler    = (void*) TC3_Handler,    /* 26 Timer/Counter 3 */
	.pfnTC4_Handler    = (void*) TC4_Handler,    /* 27 Timer/Counter 4 */
	.pfnTC5_Handler    = (void*) TC5_Handler,    /* 28 Timer/Counter 5 */
	.pfnADC_Handler    = (void*) ADC_Handler,    /* 29 Analog To Digital Converter */
	.pfnDACC_Handler   = (void*) DACC_Handler,   /* 30 Digital To Analog Converter */
	.pfnPWM_Handler    = (void*) PWM_Handler     /* 31 Pulse Width Modulation */
};
