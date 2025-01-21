// buttonblink:  	blink an LED on the NUCLEO-F411 board.
// 					test file for toolchain, environment and board.

#include "stm32f4xx.h"
#include "core_cm4.h"
#include "systick.h"
#include "gpio.h"


int main(void) 
{
	led_init();

	// toggle LED
	while (1)
	{
		// delay for 500 ms using SysTick timer
		systick_delay_msec(500);
		led_toggle();
	}
}
