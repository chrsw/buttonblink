// buttonblink:  	blink an LED on the NUCLEO-F411 board when user button is pressed.
// 					test project for toolchain, environment and board.

#include "stm32f4xx.h"
#include "core_cm4.h"
#include "systick.h"
#include "gpio.h"
#include "tim.h"

int btn_state = 0;

int main(void) 
{
	led_init();
	tim2_1hz_init();
	button_init();

	
	led_on();

	while (1)
	{
		// wait for timer event
		while(!(TIM2->SR & SR_UIF)) {}
		// clear event flag
		TIM2->SR &= ~SR_UIF;
		led_toggle();
		
		//led_off();
		// check button state
		get_btn_state();
		if (btn_state)
		{
			//led_on();
		} else
		{
			led_off();
			//led_off();
		}
	}
}
