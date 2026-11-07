#include "buzzer.h"

Buzzer buzzer_new(TIM_HandleTypeDef* htim, uint32_t channel)
{
	return (Buzzer){htim, channel, false};
}

void buzzer_on(Buzzer* buzzer)
{
	buzzer->on = true;
	HAL_TIM_PWM_Start(buzzer->htim, buzzer->channel);
}

void buzzer_off(Buzzer* buzzer)
{
	buzzer->on = false;
	HAL_TIM_PWM_Stop(buzzer->htim, buzzer->channel);
}

bool buzzer_is_on(Buzzer* buzzer)
{
	return buzzer->on;
}
