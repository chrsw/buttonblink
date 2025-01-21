// STM32 SysTick Timer driver

#include "systick.h"

#define CTRL_ENABLE         (1U<<0)
#define CTRL_CLKSRC         (1U<<2)
#define CTRL_COUNTFLAG      (1U<<16)

// default MCU frequency is 16 MHz
#define ONE_MSEC_LOAD       16000

void systick_delay_msec(uint32_t delay)
{
    // load number of clock cycles per millisecond
    SysTick->LOAD = ONE_MSEC_LOAD -1;

    // clear SysTick current value register
    SysTick->VAL = 0;

    // select internal clock source
    SysTick->CTRL = CTRL_CLKSRC;

    // enable SysTick
    SysTick->CTRL |= CTRL_ENABLE;

    // wait for specified delay
    for (int i = 0; i < delay; i++)
    {
        while((SysTick->CTRL & CTRL_COUNTFLAG) == 0) {}
    }

    // disable SysTick
    SysTick->CTRL = 0;
}