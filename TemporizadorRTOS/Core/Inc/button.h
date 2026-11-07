#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdbool.h>
#include "main.h"
#include "gpio_pin.h"


// Time of wait for rebound on the botton
const static int TIME_REBOUND_MS = 100;
// Not pressing state
const static int INICIAL_VALID_STATE = GPIO_PIN_SET;

typedef struct
{
	Gpio_pin input_pin;
	GPIO_PinState read;
	uint32_t read_time;
} Button;

Button button_new(GPIO_TypeDef* port, uint16_t pin);

// Verify if the interruption for pressing is valid
bool button_check_pressed(Button* button);

#endif
