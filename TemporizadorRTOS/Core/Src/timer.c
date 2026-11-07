#include "timer.h"


Timer timer_new(unsigned long miliseconds)
{
	return (Timer){miliseconds, false, false};
}

void timer_set(Timer* timer, unsigned long miliseconds)
{
	timer->miliseconds = miliseconds;
	timer->counting = false;
	timer->finished = false;
}

void timer_start(Timer* timer)
{
	timer->counting = true;
	timer->finished = false;
}

void timer_reset(Timer* timer)
{
	timer->miliseconds = 0;
	timer->counting = false;
	timer->finished = false;
}

void timer_pause(Timer* timer)
{
	timer->counting = false;
}

bool timer_is_counting(Timer* timer)
{
	return timer->counting;
}

bool timer_is_finished(Timer* timer)
{
	return timer->finished;
}

void timer_add(Timer* t, long int time_to_add)
{
	t->miliseconds += time_to_add;
}

void timer_substract(Timer* t, long int time_to_subtract)
{
	 if (t->miliseconds >= time_to_subtract)
	{
		t->miliseconds -= time_to_subtract;
	}
	else
	{
		t->miliseconds = 0;
		t->counting = false;
		t->finished = true;
	}
}

// Devuelve el digito del tiempo
// ej:     000 143 , 265 [s]
// digito: 876 543 , 210
short timer_get_digit(Timer* t, int digito)
{
    unsigned long temp = t->miliseconds;

    // Dividimos por 10 tantas veces como el valor de 'digito'
    for (int i = 0; i < digito; i++) {
        temp /= 10;
    }

    // Nos quedamos con el último número (el de la derecha)
    return (short)(temp % 10);
}

unsigned long timer_get_seconds(Timer* t)
{
	return (t->miliseconds / 1000);
}

unsigned long timer_get_minutes(Timer* t)
{
	unsigned long seconds = timer_get_seconds(t);
	unsigned long minutes = seconds/60;
	return minutes;
}

short timer_get_minutes_digit(Timer* t, int digito)
{
    unsigned long minutes = timer_get_minutes(t);

    // Dividimos por 10 tantas veces como el valor de 'digito'
    for (int i = 0; i < digito; i++) {
        minutes /= 10;
    }

    // Nos quedamos con el último número
    return (short)(minutes % 10);
}

short timer_get_seconds_digit(Timer* t, int digito)
{
    // Obtenemos solo la porción de segundos (0-59)
    unsigned long seconds = timer_get_seconds(t) % 60;

    // Dividimos por 10 tantas veces como el valor de 'digito'
    for (int i = 0; i < digito; i++) {
        seconds /= 10;
    }

    // Nos quedamos con el último número
    return (short)(seconds % 10);
}
