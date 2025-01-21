// buttonblink:  	blink an LED on the NUCLEO-F411 board 
// 					test file for toolchain

#include "stm32f4xx.h"
#include "core_cm4.h"
#include "gpio.h"


int main(void) 
{
	led_init();

	// toggle LED
	while (1)
	{
		led_toggle();
		for (int i = 0; i < 1500000; i++) {}
	}
}
