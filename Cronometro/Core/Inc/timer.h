/*
 * time.h
 *
 *  Created on: 5 sept 2026
 *      Author: julian
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


typedef struct
{
	// El tiempo esta en milisegundo [ms]
	long int time;
} Timer;

Timer timer_new()
{
	return (Timer){0};
}

void timer_add(Timer* t, int refresh_rate)
{
	t->time += refresh_rate;
}

// Devuelve el digito del tiempo
// ej:     143[s] .265 [ms]

// digito: 543    .210
int timer_digit(Timer* t, int digito)
{
    long int temp = t->time;

    // Dividimos por 10 tantas veces como el valor de 'digito'
    for (int i = 0; i < digito; i++) {
        temp /= 10;
    }

    // Nos quedamos con el último número (el de la derecha)
    return temp % 10;
}

void timer_reset(Timer* timer)
{
	timer->time = 0;
}

#endif /* INC_TIMER_H_ */
