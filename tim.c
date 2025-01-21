// tim      STM32 TIM peripheral driver
//          users TIM2 timer

#include "tim.h"

#define TIM2EN                  (1U<<0)
#define CR1_CEN                 (1u<<0)


void tim2_1hz_init(void)
{
    // enable clock access to TIM2
    RCC->APB1ENR |= TIM2EN;

    // set prescaler value
    TIM2->PSC = 1600 - 1;

    // set auto reload value
    TIM2->ARR = 10000 - 1;
    
    // clear counter
    TIM2->CNT = 0;
    
    // enable timer
    TIM2->CR1 = CR1_CEN;
}
