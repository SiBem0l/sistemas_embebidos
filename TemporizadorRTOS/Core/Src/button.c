#include "button.h"

Button button_new(GPIO_TypeDef* port, uint16_t pin)
{
	Gpio_pin input_pin = gpio_pin_new(port, pin);
	return (Button){input_pin, INICIAL_VALID_STATE, 0};
}

// Verifica si la interrupción es válida
bool button_check_pressed(Button* button)
{
	bool pressed = false;
	uint32_t current_time = HAL_GetTick();

	if((current_time - button->read_time) > TIME_REBOUND_MS)
	{
		button->read_time = current_time;
		pressed = true;
	}

	return pressed;
}

