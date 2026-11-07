#ifndef LED_H
#define LED_H

#include "main.h"

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
	unsigned int frecuency_toggle; // [HZ]
} Led;

Led led_new(GPIO_TypeDef* port, uint16_t pin, unsigned int frecuency);
void led_toggle(Led* led);

#endif
