#include "display.h"


Display display_new()
{
	Display d;
	d.block_selector_b0 = gpio_pin_new(digit_selection_bit0_GPIO_Port, digit_selection_bit0_Pin);
	d.block_selector_b1 = gpio_pin_new(digit_selection_bit1_GPIO_Port, digit_selection_bit1_Pin);
	d.digit = digit_new();
	d.current_block = 0;
	return d;
}

void display_select_block(Display* display, int block)
{
	Gpio_pin* b0 = &(display->block_selector_b0);
	Gpio_pin* b1 = &(display->block_selector_b1);

	switch (block)
	{
	    case 0: // 00
	        HAL_GPIO_WritePin(b0->port, b0->pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(b1->port, b1->pin, GPIO_PIN_RESET);
	        break;
	    case 1: // 01
	        HAL_GPIO_WritePin(b0->port, b0->pin, GPIO_PIN_SET);
	        HAL_GPIO_WritePin(b1->port, b1->pin, GPIO_PIN_RESET);
	        break;
	    case 2: // 10
	        HAL_GPIO_WritePin(b0->port, b0->pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(b1->port, b1->pin, GPIO_PIN_SET);
	        break;
	    case 3: // 11
	        HAL_GPIO_WritePin(b0->port, b0->pin, GPIO_PIN_SET);
	        HAL_GPIO_WritePin(b1->port, b1->pin, GPIO_PIN_SET);
	        break;
	    default:
	        break;
	}
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

	display_select_block(display, block);
	digit_write(digit, value, dot);
}
