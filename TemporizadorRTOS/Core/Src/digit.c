#include "digit.h"

Digit digit_new()
{
	Digit d;
	d.segment_a = gpio_pin_new(segment_a_GPIO_Port, segment_a_Pin);
	d.segment_b = gpio_pin_new(segment_b_GPIO_Port, segment_b_Pin);
	d.segment_c = gpio_pin_new(segment_c_GPIO_Port, segment_c_Pin);
	d.segment_d = gpio_pin_new(segment_d_GPIO_Port, segment_d_Pin);
	d.segment_e = gpio_pin_new(segment_e_GPIO_Port, segment_e_Pin);
	d.segment_f = gpio_pin_new(segment_f_GPIO_Port, segment_f_Pin);
	d.segment_g = gpio_pin_new(segment_g_GPIO_Port, segment_g_Pin);
	d.dot = gpio_pin_new(dot_GPIO_Port, dot_Pin);
	return d;
}

void digit_write(Digit* digit, int value, bool dot)
{
    // Initialize all segments off by default
    GPIO_PinState a = GPIO_PIN_RESET, b = GPIO_PIN_RESET, c = GPIO_PIN_RESET;
    GPIO_PinState d = GPIO_PIN_RESET, e = GPIO_PIN_RESET, f = GPIO_PIN_RESET, g = GPIO_PIN_RESET;
    GPIO_PinState dot_state = dot == true? GPIO_PIN_SET : GPIO_PIN_RESET;

    // Segment assignment according to the number (Assuming common cathode: SET = On)
    switch (value)
    {
        case 0: a=b=c=d=e=f=GPIO_PIN_SET; break;
        case 1: b=c=GPIO_PIN_SET; break;
        case 2: a=b=d=e=g=GPIO_PIN_SET; break;
        case 3: a=b=c=d=g=GPIO_PIN_SET; break;
        case 4: b=c=f=g=GPIO_PIN_SET; break;
        case 5: a=c=d=f=g=GPIO_PIN_SET; break;
        case 6: a=c=d=e=f=g=GPIO_PIN_SET; break;
        case 7: a=b=c=GPIO_PIN_SET; break;
        case 8: a=b=c=d=e=f=g=GPIO_PIN_SET; break;
        case 9: a=b=c=d=f=g=GPIO_PIN_SET; break;
        default: break;
    }

    HAL_GPIO_WritePin(digit->segment_a.port, digit->segment_a.pin, a);
    HAL_GPIO_WritePin(digit->segment_b.port, digit->segment_b.pin, b);
    HAL_GPIO_WritePin(digit->segment_c.port, digit->segment_c.pin, c);
    HAL_GPIO_WritePin(digit->segment_d.port, digit->segment_d.pin, d);
    HAL_GPIO_WritePin(digit->segment_e.port, digit->segment_e.pin, e);
    HAL_GPIO_WritePin(digit->segment_f.port, digit->segment_f.pin, f);
    HAL_GPIO_WritePin(digit->segment_g.port, digit->segment_g.pin, g);
	HAL_GPIO_WritePin(digit->dot.port, digit->dot.pin, dot_state);
}
