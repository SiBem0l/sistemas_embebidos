#ifndef DIGIT_H
#define DIGIT_H

#include <stdbool.h>
#include "gpio_pin.h"

typedef struct
{
	// Segment name
	Gpio_pin segment_a;
	Gpio_pin segment_b;
	Gpio_pin segment_c;
	Gpio_pin segment_d;
	Gpio_pin segment_e;
	Gpio_pin segment_f;
	Gpio_pin segment_g;
	Gpio_pin dot;
} Digit;

Digit digit_new();
void digit_write(Digit* digit, int value, bool dot);

#endif
