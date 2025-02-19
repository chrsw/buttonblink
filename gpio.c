// gpio driver

#include "gpio.h"

#define GPIOAEN             (1U<<0)
#define GPIOCEN             (1U<<2)
#define LED_BS5             (1U<<5)     // bit set pin 5
#define LED_BR5             (1U<<21)    // bit reset pin 5
#define PIN5                (1U<<5)     // pin PA5
#define LED_PIN             PIN5
#define PIN13               (1U<<13)
#define BTN_PIN             PIN13


extern int btn_state;

void led_init(void)
{
    // pheripheral clocks are gated by default to save power
    // enable clock access to GPIOA
    RCC->AHB1ENR |= GPIOAEN;

    // set PA5 mode to output mode
    GPIOA->MODER |= (1U<<10); 
    GPIOA->MODER &= ~(1U<<11); 
}

void button_init(void)
{
    // enable clock access to GPIOC
    RCC->AHB1ENR |= GPIOCEN;

    // set PC13 as input pin
    GPIOC->MODER &= ~(1U<<26); 
    GPIOC->MODER &= ~(1U<<27); 
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

void get_btn_state(void)
{
    // button is active low

    // check if button is pressed
    if (GPIOC->IDR & BTN_PIN)
    {
        btn_state = 0;
    }
    else
    {
        btn_state = 1;
    }
}