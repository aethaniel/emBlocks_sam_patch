#include "atsam.h"

/**
 * \brief We assume that the main() returns, most embedded systems
 * don't do that. If your main() is not returning then you can define MAIN_DONT_RETURN.
 * By defining MAIN_DONT_RETURN, you will save some stack and code space.
 */

/* Header for end of stack, declared in linker file */
/* Sections declared in linker files: contain BSS, Zero, Stack */
extern uint32_t _sfixed;
extern uint32_t _efixed;
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _szero;
extern uint32_t _ezero;
extern uint32_t _sstack;
extern uint32_t _estack;


/**
 * \brief This is the code that gets called on processor reset.
 * A naked attribute is used to skip the prologue and epilogue,
 * this is the start of the chain.
 */
void _start(void) __attribute__ ((weak, alias("_alt_start")));
void __attribute__ ((naked)) Reset_Handler( void )
{
	register uint32_t *pSrc, *pDest;

	// Initialize the relocate segment
	pSrc = &_etext;
	pDest = &_srelocate;

	if (pSrc != pDest)
	{
		for (; pDest < &_erelocate;)
		{
			*pDest++ = *pSrc++;
		}
	}

	// Set the vector table base address
	pSrc = (uint32_t *) & _sfixed;
	SCB->VTOR = ((uint32_t) pSrc & SCB_VTOR_TBLOFF_Msk);

	// Branch to the start function in the library. If it is not
	// there, we use the _alt_start function in this module.
	//
    _start();
}


/**
 * \brief This is the alternative start code that gets called if the
 * default library start files are not used. The BSS is cleared and
 * the main function is called.
 */
extern int main(void);

void
#ifdef MAIN_DONT_RETURN
 __attribute__ ((naked))
#endif
_alt_start(void)
{
    register uint32_t *pDest;

 	// Clear the zero segment
	for (pDest = &_szero; pDest < &_ezero;)
    {
		*pDest++ = 0;
	}

    // Branch to our user application
    main();

#ifndef MAIN_DONT_RETURN
	// Infinite loop
	while (1);
#endif
}


/**
 * \brief Default interrupt handler for unused IRQs.
 */
void Dummy_Handler( void )
{
	while ( 1 )
	{
	}
}

/* Cortex-M4 core handlers */
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
void PIOA_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOB_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM4E_PIOC_INSTANCE_
void PIOC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM4E_PIOC_INSTANCE_ */
void PIOD_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM4E_PIOE_INSTANCE_
void PIOE_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM4E_PIOE_INSTANCE_ */
void USART0_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART1_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void HSMCI_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DMAC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC4_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC5_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC6_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC7_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC8_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AFEC0_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AFEC1_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DACC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ACC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ARM_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UDP_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void CAN0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM4E_CAN1_INSTANCE_
void CAN1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM4E_CAN1_INSTANCE_ */
void AES_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GMAC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART1_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

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
	.pfnWDT_Handler    = (void*) WDT_Handler,    /* 4  Watchdog/Dual Watchdog Timer */
	.pfnPMC_Handler    = (void*) PMC_Handler,    /* 5  Power Management Controller */
	.pfnEFC_Handler    = (void*) EFC_Handler,    /* 6  Enhanced Embedded Flash Controller */
	.pfnUART0_Handler  = (void*) UART0_Handler,  /* 7  UART 0 */
	.pvReserved8       = (void*) (0UL),          /* 8  Reserved */
	.pfnPIOA_Handler   = (void*) PIOA_Handler,   /* 9  Parallel I/O Controller A */
	.pfnPIOB_Handler   = (void*) PIOB_Handler,   /* 10 Parallel I/O Controller B */
#ifdef _SAM4E_PIOC_INSTANCE_
	.pfnPIOC_Handler   = (void*) PIOC_Handler,   /* 11 Parallel I/O Controller C */
#else
	.pvReserved11      = (void*) (0UL),          /* 11 Reserved */
#endif /* _SAM4E_PIOC_INSTANCE_ */
	.pfnPIOD_Handler   = (void*) PIOD_Handler,   /* 12 Parallel I/O Controller D */
#ifdef _SAM4E_PIOE_INSTANCE_
	.pfnPIOE_Handler   = (void*) PIOE_Handler,   /* 13 Parallel I/O Controller E */
#else
	.pvReserved13      = (void*) (0UL),          /* 13 Reserved */
#endif /* _SAM4E_PIOE_INSTANCE_ */
	.pfnUSART0_Handler = (void*) USART0_Handler, /* 14 USART 0 */
	.pfnUSART1_Handler = (void*) USART1_Handler, /* 15 USART 1 */
	.pfnHSMCI_Handler  = (void*) HSMCI_Handler,  /* 16 Multimedia Card Interface */
	.pfnTWI0_Handler   = (void*) TWI0_Handler,   /* 17 Two Wire Interface 0 */
	.pfnTWI1_Handler   = (void*) TWI1_Handler,   /* 18 Two Wire Interface 1 */
	.pfnSPI_Handler    = (void*) SPI_Handler,    /* 19 Serial Peripheral Interface */
	.pfnDMAC_Handler   = (void*) DMAC_Handler,   /* 20 DMAC */
	.pfnTC0_Handler    = (void*) TC0_Handler,    /* 21 Timer/Counter 0 */
	.pfnTC1_Handler    = (void*) TC1_Handler,    /* 22 Timer/Counter 1 */
	.pfnTC2_Handler    = (void*) TC2_Handler,    /* 23 Timer/Counter 2 */
	.pfnTC3_Handler    = (void*) TC3_Handler,    /* 24 Timer/Counter 3 */
	.pfnTC4_Handler    = (void*) TC4_Handler,    /* 25 Timer/Counter 4 */
	.pfnTC5_Handler    = (void*) TC5_Handler,    /* 26 Timer/Counter 5 */
	.pfnTC6_Handler    = (void*) TC6_Handler,    /* 27 Timer/Counter 6 */
	.pfnTC7_Handler    = (void*) TC7_Handler,    /* 28 Timer/Counter 7 */
	.pfnTC8_Handler    = (void*) TC8_Handler,    /* 29 Timer/Counter 8 */
	.pfnAFEC0_Handler  = (void*) AFEC0_Handler,  /* 30 Analog Front End 0 */
	.pfnAFEC1_Handler  = (void*) AFEC1_Handler,  /* 31 Analog Front End 1 */
	.pfnDACC_Handler   = (void*) DACC_Handler,   /* 32 Digital To Analog Converter */
	.pfnACC_Handler    = (void*) ACC_Handler,    /* 33 Analog Comparator */
	.pfnARM_Handler    = (void*) ARM_Handler,    /* 34 FPU signals : FPIXC, FPOFC, FPUFC, FPIOC, FPDZC, FPIDC, FPIXC */
	.pfnUDP_Handler    = (void*) UDP_Handler,    /* 35 USB DEVICE */
	.pfnPWM_Handler    = (void*) PWM_Handler,    /* 36 PWM */
	.pfnCAN0_Handler   = (void*) CAN0_Handler,   /* 37 CAN0 */
#ifdef _SAM4E_CAN1_INSTANCE_
	.pfnCAN1_Handler   = (void*) CAN1_Handler,   /* 38 CAN1 */
#else
	.pvReserved38      = (void*) (0UL),          /* 38 Reserved */
#endif /* _SAM4E_CAN1_INSTANCE_ */
	.pfnAES_Handler    = (void*) AES_Handler,    /* 39 AES */
	.pvReserved40      = (void*) (0UL),          /* 40 Reserved */
	.pvReserved41      = (void*) (0UL),          /* 41 Reserved */
	.pvReserved42      = (void*) (0UL),          /* 42 Reserved */
	.pvReserved43      = (void*) (0UL),          /* 43 Reserved */
	.pfnGMAC_Handler   = (void*) GMAC_Handler,   /* 44 EMAC */
	.pfnUART1_Handler  = (void*) UART1_Handler   /* 45 UART */
};
