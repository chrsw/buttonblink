#ifndef GPIO_H_
#define GPIO_H

#include "stm32f4xx.h"

void led_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);

#endif // GPIO_H_