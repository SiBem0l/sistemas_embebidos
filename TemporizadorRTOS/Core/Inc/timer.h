#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include <stdbool.h>

#define TIMER_REFRESH_RATE 1000 // [ms]

typedef struct
{
	volatile unsigned long miliseconds; // [ms]
	volatile bool counting;
	volatile bool finished;
} Timer;

Timer timer_new(unsigned long miliseconds);

void timer_ready(Timer* timer);
void timer_set(Timer* timer, unsigned long miliseconds);
void timer_start(Timer* timer);
void timer_reset(Timer* timer);
void timer_pause(Timer* timer);

bool timer_is_counting(Timer* timer);
bool timer_is_finished(Timer* timer);

void timer_add(Timer* t, long int time_to_add);
void timer_substract(Timer* t, long int time_to_subtract);

short timer_get_digit(Timer* t, int digito);

unsigned long timer_get_seconds(Timer* t);
unsigned long timer_get_minutes(Timer* t);

short timer_get_minutes_digit(Timer* t, int digito);
short timer_get_seconds_digit(Timer* t, int digito);

#endif /* INC_TIMER_H_ */
