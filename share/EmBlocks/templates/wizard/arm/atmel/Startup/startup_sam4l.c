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
void HFLASHC_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_0_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_1_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_2_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_3_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_4_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_5_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_6_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_7_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_8_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_9_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_10_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_11_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_12_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_13_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_14_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PDCA_15_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void CRCCU_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USBC_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PEVC_TR_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PEVC_OV_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AESA_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PM_Handler           ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SCIF_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void FREQM_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_0_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_1_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_2_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_3_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_4_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_5_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_6_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_7_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_8_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_9_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_10_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GPIO_11_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void BPM_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void BSCIF_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AST_ALARM_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AST_PER_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AST_OVF_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AST_READY_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AST_CLKREADY_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void WDT_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_2_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_3_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_4_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_5_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_6_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_7_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_8_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void IISC_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC00_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC01_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC02_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC10_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC11_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC12_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWIM0_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWIS0_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWIM1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWIS1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART0_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART1_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART2_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART3_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ADCIFE_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DACC_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ACIFC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ABDACB_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TRNG_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PARC_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void CATB_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWIM2_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWIM3_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void LCDCA_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

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
	.pfnReservedM9         = (void*) (0UL),          /* Reserved */
	.pfnReservedM8         = (void*) (0UL),          /* Reserved */
	.pfnReservedM7         = (void*) (0UL),          /* Reserved */
	.pfnReservedM6         = (void*) (0UL),          /* Reserved */
	.pfnSVC_Handler        = (void*) SVC_Handler,
	.pfnDebugMon_Handler   = (void*) DebugMon_Handler,
	.pfnReservedM3         = (void*) (0UL),          /* Reserved */
	.pfnPendSV_Handler     = (void*) PendSV_Handler,
	.pfnSysTick_Handler    = (void*) SysTick_Handler,

	/* Configurable interrupts */
	.pfnHFLASHC_Handler    = (void*) HFLASHC_Handler,      /*  0 Flash Controller */
	.pfnPDCA_0_Handler     = (void*) PDCA_0_Handler,       /*  1 Peripheral DMA Controller */
	.pfnPDCA_1_Handler     = (void*) PDCA_1_Handler,       /* 2  Peripheral DMA Controller */
	.pfnPDCA_2_Handler     = (void*) PDCA_2_Handler,       /* 3  Peripheral DMA Controller */
	.pfnPDCA_3_Handler     = (void*) PDCA_3_Handler,       /* 4  Peripheral DMA Controller */
	.pfnPDCA_4_Handler     = (void*) PDCA_4_Handler,       /* 5  Peripheral DMA Controller */
	.pfnPDCA_5_Handler     = (void*) PDCA_5_Handler,       /* 6  Peripheral DMA Controller */
	.pfnPDCA_6_Handler     = (void*) PDCA_6_Handler,       /* 7  Peripheral DMA Controller */
	.pfnPDCA_7_Handler     = (void*) PDCA_7_Handler,       /* 8  Peripheral DMA Controller */
	.pfnPDCA_8_Handler     = (void*) PDCA_8_Handler,       /* 9  Peripheral DMA Controller */
	.pfnPDCA_9_Handler     = (void*) PDCA_9_Handler,       /* 10 Peripheral DMA Controller */
	.pfnPDCA_10_Handler    = (void*) PDCA_10_Handler,      /* 11 Peripheral DMA Controller */
	.pfnPDCA_11_Handler    = (void*) PDCA_11_Handler,      /* 12 Peripheral DMA Controller */
	.pfnPDCA_12_Handler    = (void*) PDCA_12_Handler,      /* 13 Peripheral DMA Controller */
	.pfnPDCA_13_Handler    = (void*) PDCA_13_Handler,      /* 14 Peripheral DMA Controller */
	.pfnPDCA_14_Handler    = (void*) PDCA_14_Handler,      /* 15 Peripheral DMA Controller */
	.pfnPDCA_15_Handler    = (void*) PDCA_15_Handler,      /* 16 Peripheral DMA Controller */
	.pfnCRCCU_Handler      = (void*) CRCCU_Handler,        /* 17 CRC Calculation Unit */
	.pfnUSBC_Handler       = (void*) USBC_Handler,         /* 18 USB 2.0 Interface */
	.pfnPEVC_TR_Handler    = (void*) PEVC_TR_Handler,      /* 19 Peripheral Event Controller */
	.pfnPEVC_OV_Handler    = (void*) PEVC_OV_Handler,      /* 20 Peripheral Event Controller */
#ifdef AESA
	.pfnAESA_Handler       = (void*) AESA_Handler,         /* 21 Advanced Encryption Standard */
#else
	.pfnAESA_Handler       = (void*) Dummy_Handler,
#endif
	.pfnPM_Handler         = (void*) PM_Handler,           /* 22 Power Manager */
	.pfnSCIF_Handler       = (void*) SCIF_Handler,         /* 23 System Control Interface */
	.pfnFREQM_Handler      = (void*) FREQM_Handler,        /* 24 Frequency Meter */
	.pfnGPIO_0_Handler     = (void*) GPIO_0_Handler,       /* 25 General-Purpose Input/Output Controller */
	.pfnGPIO_1_Handler     = (void*) GPIO_1_Handler,       /* 26 General-Purpose Input/Output Controller */
	.pfnGPIO_2_Handler     = (void*) GPIO_2_Handler,       /* 27 General-Purpose Input/Output Controller */
	.pfnGPIO_3_Handler     = (void*) GPIO_3_Handler,       /* 28 General-Purpose Input/Output Controller */
	.pfnGPIO_4_Handler     = (void*) GPIO_4_Handler,       /* 29 General-Purpose Input/Output Controller */
	.pfnGPIO_5_Handler     = (void*) GPIO_5_Handler,       /* 30 General-Purpose Input/Output Controller */
	.pfnGPIO_6_Handler     = (void*) GPIO_6_Handler,       /* 31 General-Purpose Input/Output Controller */
	.pfnGPIO_7_Handler     = (void*) GPIO_7_Handler,       /* 32 General-Purpose Input/Output Controller */
	.pfnGPIO_8_Handler     = (void*) GPIO_8_Handler,       /* 33 General-Purpose Input/Output Controller */
	.pfnGPIO_9_Handler     = (void*) GPIO_9_Handler,       /* 34 General-Purpose Input/Output Controller */
	.pfnGPIO_10_Handler    = (void*) GPIO_10_Handler,      /* 35 General-Purpose Input/Output Controller */
	.pfnGPIO_11_Handler    = (void*) GPIO_11_Handler,      /* 36 General-Purpose Input/Output Controller */
	.pfnBPM_Handler        = (void*) BPM_Handler,          /* 37 Backup Power Manager */
	.pfnBSCIF_Handler      = (void*) BSCIF_Handler,        /* 38 Backup System Control Interface */
	.pfnAST_ALARM_Handler  = (void*) AST_ALARM_Handler,    /* 39 Asynchronous Timer */
	.pfnAST_PER_Handler    = (void*) AST_PER_Handler,      /* 40 Asynchronous Timer */
	.pfnAST_OVF_Handler    = (void*) AST_OVF_Handler,      /* 41 Asynchronous Timer */
	.pfnAST_READY_Handler  = (void*) AST_READY_Handler,    /* 42 Asynchronous Timer */
	.pfnAST_CLKREADY_Handler = (void*) AST_CLKREADY_Handler, /* 43 Asynchronous Timer */
	.pfnWDT_Handler        = (void*) WDT_Handler,          /* 44 Watchdog Timer */
	.pfnEIC_1_Handler      = (void*) EIC_1_Handler,        /* 45 External Interrupt Controller */
	.pfnEIC_2_Handler      = (void*) EIC_2_Handler,        /* 46 External Interrupt Controller */
	.pfnEIC_3_Handler      = (void*) EIC_3_Handler,        /* 47 External Interrupt Controller */
	.pfnEIC_4_Handler      = (void*) EIC_4_Handler,        /* 48 External Interrupt Controller */
	.pfnEIC_5_Handler      = (void*) EIC_5_Handler,        /* 49 External Interrupt Controller */
	.pfnEIC_6_Handler      = (void*) EIC_6_Handler,        /* 50 External Interrupt Controller */
	.pfnEIC_7_Handler      = (void*) EIC_7_Handler,        /* 51 External Interrupt Controller */
	.pfnEIC_8_Handler      = (void*) EIC_8_Handler,        /* 52 External Interrupt Controller */
	.pfnIISC_Handler       = (void*) IISC_Handler,         /* 53 Inter-IC Sound (I2S) Controller */
	.pfnSPI_Handler        = (void*) SPI_Handler,          /* 54 Serial Peripheral Interface */
	.pfnTC00_Handler       = (void*) TC00_Handler,         /* 55 Timer/Counter 0 */
	.pfnTC01_Handler       = (void*) TC01_Handler,         /* 56 Timer/Counter 0 */
	.pfnTC02_Handler       = (void*) TC02_Handler,         /* 57 Timer/Counter 0 */
	.pfnTC10_Handler       = (void*) TC10_Handler,         /* 58 Timer/Counter 1 */
	.pfnTC11_Handler       = (void*) TC11_Handler,         /* 59 Timer/Counter 1 */
	.pfnTC12_Handler       = (void*) TC12_Handler,         /* 60 Timer/Counter 1 */
	.pfnTWIM0_Handler      = (void*) TWIM0_Handler,        /* 61 Two-wire Master Interface 0 */
	.pfnTWIS0_Handler      = (void*) TWIS0_Handler,        /* 62 Two-wire Slave Interface 0 */
	.pfnTWIM1_Handler      = (void*) TWIM1_Handler,        /* 63 Two-wire Master Interface 1 */
	.pfnTWIS1_Handler      = (void*) TWIS1_Handler,        /* 64 Two-wire Slave Interface 1 */
	.pfnUSART0_Handler     = (void*) USART0_Handler,       /* 65 Universal Synchronous Asynchronous Receiver Transmitter 0 */
	.pfnUSART1_Handler     = (void*) USART1_Handler,       /* 66 Universal Synchronous Asynchronous Receiver Transmitter 1 */
	.pfnUSART2_Handler     = (void*) USART2_Handler,       /* 67 Universal Synchronous Asynchronous Receiver Transmitter 2 */
	.pfnUSART3_Handler     = (void*) USART3_Handler,       /* 68 Universal Synchronous Asynchronous Receiver Transmitter 3 */
	.pfnADCIFE_Handler     = (void*) ADCIFE_Handler,       /* 69 ADC controller interface */
	.pfnDACC_Handler       = (void*) DACC_Handler,         /* 70 DAC Controller */
	.pfnACIFC_Handler      = (void*) ACIFC_Handler,        /* 71 Analog Comparator Interface */
	.pfnABDACB_Handler     = (void*) ABDACB_Handler,       /* 72 Audio Bitstream DAC */
	.pfnTRNG_Handler       = (void*) TRNG_Handler,         /* 73 True Random Number Generator */
	.pfnPARC_Handler       = (void*) PARC_Handler,         /* 74 Parallel Capture */
	.pfnCATB_Handler       = (void*) CATB_Handler,         /* 75 Capacitive Touch Module B */
	.pfnReserved76         = (void*) Dummy_Handler,        // one not used
	.pfnTWIM2_Handler      = (void*) TWIM2_Handler,        /* 77 Two-wire Master Interface 2 */
	.pfnTWIM3_Handler      = (void*) TWIM3_Handler,        /* 78 Two-wire Master Interface 3 */
#ifdef LCDCA
	.pfnLCDCA_Handler      = (void*) LCDCA_Handler         /* 79 LCD Controller */
#else
	.pfnLCDCA_Handler   = (void*) Dummy_Handler
#endif
};

