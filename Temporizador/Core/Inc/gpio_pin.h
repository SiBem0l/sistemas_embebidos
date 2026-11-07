#ifndef GPIO_PIN_H
#define GPIO_PIN_H

#include "main.h"

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
} Gpio_pin;

Gpio_pin gpio_pin_new(GPIO_TypeDef* port, uint16_t pin);

#endif
