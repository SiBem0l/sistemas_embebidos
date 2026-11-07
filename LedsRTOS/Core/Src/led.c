#include "led.h"

Led led_new(GPIO_TypeDef* port, uint16_t pin, unsigned int frecuency)
{
	return (Led){port, pin, frecuency};
}

void led_toggle(Led* led)
{
	HAL_GPIO_TogglePin(led->port, led->pin);
	HAL_Delay(2);
}

