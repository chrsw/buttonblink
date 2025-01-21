// buttonblink:  	blink an LED on the NUCLEO-F411 board.
// 					test file for toolchain, environment and board.

#include "stm32f4xx.h"
#include "core_cm4.h"
#include "systick.h"
#include "gpio.h"
#include "tim.h"


int main(void) 
{
	led_init();
	tim2_1hz_init();

	// toggle LED
	while (1)
	{
		// wait for timer event
		while(!(TIM2->SR & SR_UIF)) {}
		// clear event flag
		TIM2->SR &= ~SR_UIF;
		led_toggle();
	}
}
