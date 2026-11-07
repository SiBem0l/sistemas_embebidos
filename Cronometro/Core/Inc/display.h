/*
 * display.h
 *
 *  Created on: 5 sept 2026
 *      Author: julian
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "digit.h"

#define N_BLOCKS 4

typedef struct
{
	Digit digit;
	int current_block;
} Display;

Display display_new()
{
	return (Display){digit_new(), 0};
}

void display_next_block(Display* display)
{
	if(display->current_block < N_BLOCKS-1)
	{
		display->current_block++;
	}
	else
	{
		display->current_block = 0;
	}
}

void display_show(Display* display, int value)
{
	Digit* digit = &(display->digit);
	int block = display->current_block;
	bool dot = (block == 2);
	digit_show(digit, block, value, dot);
}
#endif /* INC_DISPLAY_H_ */
