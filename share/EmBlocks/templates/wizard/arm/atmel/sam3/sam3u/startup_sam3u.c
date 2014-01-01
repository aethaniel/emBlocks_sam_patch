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
void EFC0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3U_EFC1_INSTANCE_
void EFC1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3U_EFC1_INSTANCE_ */
void UART_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOA_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOB_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3U_PIOC_INSTANCE_
void PIOC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3U_PIOC_INSTANCE_ */
void USART0_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART1_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART2_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3U_USART3_INSTANCE_
void USART3_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3U_USART3_INSTANCE_ */
void HSMCI_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SSC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC12B_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DMAC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UDPHS_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

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
	.pfnEFC0_Handler   = (void*) EFC0_Handler,   /* 6  Enhanced Embedded Flash Controller 0 */
#ifdef _SAM3U_EFC1_INSTANCE_
	.pfnEFC1_Handler   = (void*) EFC1_Handler,   /* 7  Enhanced Embedded Flash Controller 1 */
#else
	.pvReserved7       = (void*) (0UL),          /* 7  Reserved */
#endif /* _SAM3U_EFC1_INSTANCE_ */
	.pfnUART_Handler   = (void*) UART_Handler,   /* 8  Universal Asynchronous Receiver Transmitter */
	.pvReserved9       = (void*) (0UL),          /* 9  Reserved */
	.pfnPIOA_Handler   = (void*) PIOA_Handler,   /* 10 Parallel I/O Controller A, */
	.pfnPIOB_Handler   = (void*) PIOB_Handler,   /* 11 Parallel I/O Controller B */
#ifdef _SAM3U_PIOC_INSTANCE_
	.pfnPIOC_Handler   = (void*) PIOC_Handler,   /* 12 Parallel I/O Controller C */
#else
	.pvReserved12      = (void*) (0UL),          /* 12 Reserved */
#endif /* _SAM3U_PIOC_INSTANCE_ */
	.pfnUSART0_Handler = (void*) USART0_Handler, /* 13 USART 0 */
	.pfnUSART1_Handler = (void*) USART1_Handler, /* 14 USART 1 */
	.pfnUSART2_Handler = (void*) USART2_Handler, /* 15 USART 2 */
#ifdef _SAM3U_USART3_INSTANCE_
	.pfnUSART3_Handler = (void*) USART3_Handler, /* 16 USART 3 */
#else
	.pvReserved16      = (void*) (0UL),          /* 16 Reserved */
#endif /* _SAM3U_USART3_INSTANCE_ */
	.pfnHSMCI_Handler  = (void*) HSMCI_Handler,  /* 17 High Speed Multimedia Card Interface */
	.pfnTWI0_Handler   = (void*) TWI0_Handler,   /* 18 Two-Wire Interface 0 */
	.pfnTWI1_Handler   = (void*) TWI1_Handler,   /* 19 Two-Wire Interface 1 */
	.pfnSPI_Handler    = (void*) SPI_Handler,    /* 20 Serial Peripheral Interface */
	.pfnSSC_Handler    = (void*) SSC_Handler,    /* 21 Synchronous Serial Controller */
	.pfnTC0_Handler    = (void*) TC0_Handler,    /* 22 Timer Counter 0 */
	.pfnTC1_Handler    = (void*) TC1_Handler,    /* 23 Timer Counter 1 */
	.pfnTC2_Handler    = (void*) TC2_Handler,    /* 24 Timer Counter 2 */
	.pfnPWM_Handler    = (void*) PWM_Handler,    /* 25 Pulse Width Modulation Controller */
	.pfnADC12B_Handler = (void*) ADC12B_Handler, /* 26 12-bit ADC Controller */
	.pfnADC_Handler    = (void*) ADC_Handler,    /* 27 10-bit ADC Controller */
	.pfnDMAC_Handler   = (void*) DMAC_Handler,   /* 28 DMA Controller */
	.pfnUDPHS_Handler  = (void*) UDPHS_Handler   /* 29 USB Device High Speed */
};
