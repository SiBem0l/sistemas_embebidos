#ifndef LED_H
#define LED_H

#include "main.h"

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
} Led;

Led led_new(GPIO_TypeDef* port, uint16_t pin)
{
	return (Led){port, pin};
}

void led_toggle(Led led)
{
	HAL_GPIO_TogglePin(led.port, led.pin);
}

#endif
