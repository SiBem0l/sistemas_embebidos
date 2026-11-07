#include "gpio_pin.h"


Gpio_pin gpio_pin_new(GPIO_TypeDef* port, uint16_t pin)
{
	return (Gpio_pin){port,pin};
}
