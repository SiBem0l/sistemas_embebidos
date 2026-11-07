#ifndef BUZZER_H
#define BUZZER_H

#include <stdbool.h>
#include "main.h"
#include "gpio_pin.h"

typedef struct
{
	TIM_HandleTypeDef* htim;
	uint32_t channel;
	volatile bool on; // Could be modify in an interruption
} Buzzer;

Buzzer buzzer_new(TIM_HandleTypeDef* htim, uint32_t channel);

void buzzer_on(Buzzer* buzzer);
void buzzer_off(Buzzer* buzzer);

bool buzzer_is_on(Buzzer* buzzer);

#endif
