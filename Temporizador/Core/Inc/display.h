#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "digit.h"

static const int N_BLOCKS = 4;

typedef struct
{
	Digit digit;
	int current_block;

	// Block selector
	Gpio_pin block_selector_b0;
	Gpio_pin block_selector_b1;
} Display;

Display display_new();
void display_select_block(Display* display, int block);
void display_next_block(Display* display);
void display_show(Display* display, int value);

#endif /* INC_DISPLAY_H_ */
