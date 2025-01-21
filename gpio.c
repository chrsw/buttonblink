// gpio driver

#include "gpio.h"

#define GPIOAEN             (1U<<0)
#define LED_BS5             (1U<<5)     // bit set pin 5
#define LED_BR5             (1U<<21)    // bit reset pin 5
#define PIN5                (1U<<5)     // pin PA5
#define LED_PIN             PIN5

void led_init(void)
{
    // enable clock access to GPIOA
    RCC->AHB1ENR |= GPIOAEN;
    // set PA5 mode to output mode
    GPIOA->MODER |= (1U<<10); 
    GPIOA->MODER &= ~(1U<<11); 
}


void led_on(void)
{
    // set PA5 high
    GPIOA->BSRR |= LED_BS5;
}


void led_off(void)
{
    // clear PA5 low
    GPIOA->BSRR |= LED_BS5;
}


void led_toggle(void)
{
    GPIOA->ODR ^= LED_PIN;
}