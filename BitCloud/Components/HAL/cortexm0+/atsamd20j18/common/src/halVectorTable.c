/**************************************************************************//**
\file  halVectorTable.c

\brief Cortex-M3 vector table.

\author
    Atmel Corporation: http://www.atmel.com \n
    Support email: avr@atmel.com

  Copyright (c) 2008-2015, Atmel Corporation. All rights reserved.
  Licensed under Atmel's Limited License Agreement (BitCloudTM).

\internal
  History:
    19/08/13 Agasthian.s - Created
*******************************************************************************/

/******************************************************************************
                   Includes section
******************************************************************************/
#include <atsamd20.h>
#include <halInterrupt.h>
#include <sysUtils.h>

/******************************************************************************
                   Define(s) section
******************************************************************************/
#if defined(HAL_USE_USART)
#  define HAL_USART0_IRQ_HANDLER        usart0Handler
#  define HAL_USART1_IRQ_HANDLER        usart1Handler
#else
#  define HAL_USART0_IRQ_HANDLER        halIrqHandlerNotUsed
#  define HAL_USART1_IRQ_HANDLER        halIrqHandlerNotUsed
#endif
#if defined(HAL_USE_UART)
#  define HAL_UART0_IRQ_HANDLER         uart0Handler
#  define HAL_UART1_IRQ_HANDLER         uart1Handler
#else
#  define HAL_UART0_IRQ_HANDLER         halIrqHandlerNotUsed
#  define HAL_UART1_IRQ_HANDLER         halIrqHandlerNotUsed
#endif
#if defined(HAL_USE_WDT)
#  define HAL_WDT_IRQ_HANDLER         wdtTimerHandler
#else
#  define HAL_WDT_IRQ_HANDLER         halIrqHandlerNotUsed
#endif

/*******************************************************************************
                   Prototypes section
*******************************************************************************/
extern void halLowLevelInit(void);
extern void __iar_program_start(void);
extern void gccReset(void);
extern void timerHandler(void);
extern void eicHandler(void);
extern void wdtTimerHandler(void);
static void halIrqHandlerNotUsed(void);
extern void usart0Handler(void);
extern void usart1Handler(void);
extern void halMacTimerHandler(void);
/*******************************************************************************
                     External variables section
*******************************************************************************/
extern uint32_t __main_stack_top;
/* Initialize segments */

extern unsigned int _etext;
extern unsigned int _data;
extern unsigned int _edata;
extern unsigned int _bss;
extern unsigned int _ebss;

/** \cond DOXYGEN_SHOULD_SKIP_THIS */
int main(void);
/** \endcond */

void __libc_init_array(void);

/******************************************************************************
                              Constants section
******************************************************************************/

#ifdef  __IAR_SYSTEMS_ICC__
  #pragma segment="CSTACK"
  #define STACK_TOP  __sfe("CSTACK")
  #define RESET_ADDR  __iar_program_start
  #pragma language=extended
#elif __GNUC__
  #define STACK_TOP   &__main_stack_top
  #define RESET_ADDR  gccReset
#else
  #error "Unsupported compiler"
#endif

// Initial constant vector table. Used at startup only. After reset, vector table is
// relocated (remapped) to a runtime-configurable __ram_vector_table. (located in RAM)
// IAR really wants this variable to be named __vector_table. User-configurable interrupts
// are omitted, since they should not be used until remap and system init .
#ifdef __IAR_SYSTEMS_ICC__
  #pragma section = ".vectors"
  #pragma location = ".vectors"
#else
  __attribute__ ((section(".vectors")))
#endif
const HalIntVector_t __vector_table[] =
{
    {.__ptr = STACK_TOP},
    {RESET_ADDR},

    {0},
    {0},
    {0}, {0}, {0}, {0}, {0}, {0}, {0},   /* Reserved */
    {0},
    {0}, {0},                      /*  Reserved */
    {0},
    {0}
};

// Real RAM-based vector table. Some positions are already populated by BitCloud handlers
#ifdef  __IAR_SYSTEMS_ICC__
  #pragma section = ".ramvectors"
  #pragma location = ".ramvectors"
#else
  __attribute__ ((section(".ramvectors"), used))
#endif
HalIntVector_t __ram_vector_table[] =
{
    {.__ptr = STACK_TOP},
    {RESET_ADDR},

    {0},
    {0},
    {0}, {0}, {0}, {0}, {0}, {0}, {0},   /* Reserved */
    {0},
    {0}, {0},                      /*  Reserved */
    {0},
    {0},

    {halIrqHandlerNotUsed},        /*  0  POWER MANAGER (PM) */
    {halIrqHandlerNotUsed},        /*  1  SYSTEM CONTROL (SYSCTRL) */
    {HAL_WDT_IRQ_HANDLER},        /*  2  WATCHDOG TIMER */
    {halIrqHandlerNotUsed},        /*  3  REAL TIME CLOCK */
    {eicHandler},        /*  4  EXTERNAL INTERRUPT CONTROLLER (EIC) */
    {halIrqHandlerNotUsed},        /*  5  NON-VOLATILE MEMORY CONTROLLER(NVMCTRL) */
    {halIrqHandlerNotUsed},        /*  6  EVENT SYSTEM INTERFACE (EVSYS) */
    {0},       /*  7  SERIAL COMMUICATION INTERFACE 0 (SERCOM0) */
    {0},       /*  8  SERIAL COMMUICATION INTERFACE 1 (SERCOM1) */
    {halIrqHandlerNotUsed},        /*  9  SERIAL COMMUICATION INTERFACE 2 (SERCOM2) */
    {HAL_USART0_IRQ_HANDLER},        /*  10  SERIAL COMMUICATION INTERFACE 3 (SERCOM3) */
    {HAL_USART1_IRQ_HANDLER},        /*  11  SERIAL COMMUICATION INTERFACE 4 (SERCOM4) */
    {halIrqHandlerNotUsed},        /*  12  SERIAL COMMUICATION INTERFACE 5 (SERCOM5) */
    {timerHandler},                /*  13 Timer Counter 0 */
    {halMacTimerHandler},          /*  14 Timer Counter 1 */
    {halIrqHandlerNotUsed},        /*  15 Timer Counter 2 */
    {halIrqHandlerNotUsed},        /*  16 Timer Counter 3 */
    {halIrqHandlerNotUsed},        /*  17 Timer Counter 4 */
    {halIrqHandlerNotUsed},        /*  18 Timer Counter 5 */
    {halIrqHandlerNotUsed},        /*  19 Timer Counter 6 */
    {halIrqHandlerNotUsed},        /*  20 Timer Counter 7 */
    {halIrqHandlerNotUsed},        /*  21 ADC controller */
    {halIrqHandlerNotUsed},        /*  22 Analog Comparator */
    {halIrqHandlerNotUsed},        /*  23 DAC controller */
    
    {halIrqHandlerNotUsed}        /*  24 not used */
    
};

/**************************************************************************//**
\brief Default interrupt handler for not used irq.
******************************************************************************/
static void halIrqHandlerNotUsed(void)
{
  while(1);
}
/**************************************************************************//**
\brief Register interrupt handler in vector table

\param[in] num - number of irq vector starting from zeroth IRQ handler (IRQ0)
\param[in] handler - vector handler function. Pass NULL to unregister vector
\return true if succeed, false otherwise
******************************************************************************/
bool HAL_InstallInterruptVector(int32_t num, HalIntFunc_t handler)
{
  num += 16; // Offset to zeroth user interrupt location (IRQ0)

  // Writes to out-of-bound location or to stack pointer position are forbidden
  if (num >= (int32_t) ARRAY_SIZE(__ram_vector_table) || num < 1)
    return false;

  __ram_vector_table[num].__fun = handler ? handler :  halIrqHandlerNotUsed;
  return true;
}

// eof halVectorTable.c