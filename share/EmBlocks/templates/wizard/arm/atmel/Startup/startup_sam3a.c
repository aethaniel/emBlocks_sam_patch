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
void EFC1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_SMC_INSTANCE_
void SMC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_SMC_INSTANCE_ */
#ifdef _SAM3XA_SDRAMC_INSTANCE_
void SDRAMC_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_SDRAMC_INSTANCE_ */
void PIOA_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOB_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_PIOC_INSTANCE_
void PIOC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOC_INSTANCE_ */
#ifdef _SAM3XA_PIOD_INSTANCE_
void PIOD_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOD_INSTANCE_ */
#ifdef _SAM3XA_PIOE_INSTANCE_
void PIOE_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOE_INSTANCE_ */
#ifdef _SAM3XA_PIOF_INSTANCE_
void PIOF_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOF_INSTANCE_ */
void USART0_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART1_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART2_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_USART3_INSTANCE_
void USART3_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_USART3_INSTANCE_ */
void HSMCI_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_SPI1_INSTANCE_
void SPI1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_SPI1_INSTANCE_ */
void SSC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC4_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC5_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC6_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC7_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC8_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DACC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DMAC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UOTGHS_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TRNG_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_EMAC_INSTANCE_
void EMAC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_EMAC_INSTANCE_ */
void CAN0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void CAN1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

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
	.pfnEFC0_Handler   = (void*) EFC0_Handler,   /* 6  Enhanced Flash Controller 0 */
	.pfnEFC1_Handler   = (void*) EFC1_Handler,   /* 7  Enhanced Flash Controller 1 */
	.pfnUART_Handler   = (void*) UART_Handler,   /* 8  Universal Asynchronous Receiver Transceiver */
#ifdef _SAM3XA_SMC_INSTANCE_
	.pfnSMC_Handler    = (void*) SMC_Handler,    /* 9  Static Memory Controller */
#else
	.pvReserved9       = (void*) (0UL),          /* 9  Reserved */
#endif /* _SAM3XA_SMC_INSTANCE_ */
#ifdef _SAM3XA_SDRAMC_INSTANCE_
	.pfnSDRAMC_Handler = (void*) SDRAMC_Handler, /* 10 Synchronous Dynamic RAM Controller */
#else
	.pvReserved10      = (void*) (0UL),          /* 10 Reserved */
#endif /* _SAM3XA_SDRAMC_INSTANCE_ */
	.pfnPIOA_Handler   = (void*) PIOA_Handler,   /* 11 Parallel I/O Controller A, */
	.pfnPIOB_Handler   = (void*) PIOB_Handler,   /* 12 Parallel I/O Controller B */
#ifdef _SAM3XA_PIOC_INSTANCE_
	.pfnPIOC_Handler   = (void*) PIOC_Handler,   /* 13 Parallel I/O Controller C */
#else
	.pvReserved13      = (void*) (0UL),          /* 13 Reserved */
#endif /* _SAM3XA_PIOC_INSTANCE_ */
#ifdef _SAM3XA_PIOD_INSTANCE_
	.pfnPIOD_Handler   = (void*) PIOD_Handler,   /* 14 Parallel I/O Controller D */
#else
	.pvReserved14      = (void*) (0UL),          /* 14 Reserved */
#endif /* _SAM3XA_PIOD_INSTANCE_ */
#ifdef _SAM3XA_PIOE_INSTANCE_
	.pfnPIOE_Handler   = (void*) PIOE_Handler,   /* 15 Parallel I/O Controller E */
#else
	.pvReserved15      = (void*) (0UL),          /* 15 Reserved */
#endif /* _SAM3XA_PIOE_INSTANCE_ */
#ifdef _SAM3XA_PIOF_INSTANCE_
	.pfnPIOF_Handler   = (void*) PIOF_Handler,   /* 16 Parallel I/O Controller F */
#else
	.pvReserved16      = (void*) (0UL),          /* 16 Reserved */
#endif /* _SAM3XA_PIOF_INSTANCE_ */
	.pfnUSART0_Handler = (void*) USART0_Handler, /* 17 USART 0 */
	.pfnUSART1_Handler = (void*) USART1_Handler, /* 18 USART 1 */
	.pfnUSART2_Handler = (void*) USART2_Handler, /* 19 USART 2 */
#ifdef _SAM3XA_USART3_INSTANCE_
	.pfnUSART3_Handler = (void*) USART3_Handler, /* 20 USART 3 */
#else
	.pvReserved20      = (void*) (0UL),          /* 20 Reserved */
#endif /* _SAM3XA_USART3_INSTANCE_ */
	.pfnHSMCI_Handler  = (void*) HSMCI_Handler,  /* 21 Multimedia Card Interface */
	.pfnTWI0_Handler   = (void*) TWI0_Handler,   /* 22 Two-Wire Interface 0 */
	.pfnTWI1_Handler   = (void*) TWI1_Handler,   /* 23 Two-Wire Interface 1 */
	.pfnSPI0_Handler   = (void*) SPI0_Handler,   /* 24 Serial Peripheral Interface */
#ifdef _SAM3XA_SPI1_INSTANCE_
	.pfnSPI1_Handler   = (void*) SPI1_Handler,   /* 25 Serial Peripheral Interface */
#else
	.pvReserved25      = (void*) (0UL),          /* 25 Reserved */
#endif /* _SAM3XA_SPI1_INSTANCE_ */
	.pfnSSC_Handler    = (void*) SSC_Handler,    /* 26 Synchronous Serial Controller */
	.pfnTC0_Handler    = (void*) TC0_Handler,    /* 27 Timer Counter 0 */
	.pfnTC1_Handler    = (void*) TC1_Handler,    /* 28 Timer Counter 1 */
	.pfnTC2_Handler    = (void*) TC2_Handler,    /* 29 Timer Counter 2 */
	.pfnTC3_Handler    = (void*) TC3_Handler,    /* 30 Timer Counter 3 */
	.pfnTC4_Handler    = (void*) TC4_Handler,    /* 31 Timer Counter 4 */
	.pfnTC5_Handler    = (void*) TC5_Handler,    /* 32 Timer Counter 5 */
	.pfnTC6_Handler    = (void*) TC6_Handler,    /* 33 Timer Counter 6 */
	.pfnTC7_Handler    = (void*) TC7_Handler,    /* 34 Timer Counter 7 */
	.pfnTC8_Handler    = (void*) TC8_Handler,    /* 35 Timer Counter 8 */
	.pfnPWM_Handler    = (void*) PWM_Handler,    /* 36 Pulse Width Modulation Controller */
	.pfnADC_Handler    = (void*) ADC_Handler,    /* 37 ADC Controller */
	.pfnDACC_Handler   = (void*) DACC_Handler,   /* 38 DAC Controller */
	.pfnDMAC_Handler   = (void*) DMAC_Handler,   /* 39 DMA Controller */
	.pfnUOTGHS_Handler = (void*) UOTGHS_Handler, /* 40 USB OTG High Speed */
	.pfnTRNG_Handler   = (void*) TRNG_Handler,   /* 41 True Random Number Generator */
#ifdef _SAM3XA_EMAC_INSTANCE_
	.pfnEMAC_Handler   = (void*) EMAC_Handler,   /* 42 Ethernet MAC */
#else
	.pvReserved42      = (void*) (0UL),          /* 42 Reserved */
#endif /* _SAM3XA_EMAC_INSTANCE_ */
	.pfnCAN0_Handler   = (void*) CAN0_Handler,   /* 43 CAN Controller 0 */
	.pfnCAN1_Handler   = (void*) CAN1_Handler    /* 44 CAN Controller 1 */
};
