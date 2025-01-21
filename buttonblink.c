// buttonblink:  	blink an LED on the NUCLEO-F411 board 
// 					test file for toolchain

#include "stm32f4xx.h"
#include "core_cm4.h"

// LED pin
#define GPIOAEN						(1U<<0)
#define PIN5						(1U<<5)
#define LED_PIN						PIN5


int main(void) 
{
	// enable GPIOA clock
	RCC->AHB1ENR |= GPIOAEN;
	// set PA5 to output
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);
	
	// toggle LED
	while (1)
	{
		GPIOA->ODR ^= LED_PIN;
		for (int i = 0; i < 500000; i++) {}
	}
}
