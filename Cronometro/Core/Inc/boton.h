/*
 * boton.h
 *
 *  Created on: 8 sept 2026
 *      Author: julian
 */

#ifndef INC_BOTON_H_
#define INC_BOTON_H_


#include <stdbool.h>
#include "main.h"

// Tiempo de espera por rebote en el pulsador
const static int T_REBOTE_MS = 50;
// Cual es el estado inicial del boton sin apretar
const static int ESTADO_VALIDO_INICIAL = GPIO_PIN_SET;


typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
	GPIO_PinState estado_boton;
	uint32_t last_read_time;
	bool state;
} Boton;

Boton boton_new(GPIO_TypeDef* port, uint16_t pin)
{
	Boton b = {port, pin, ESTADO_VALIDO_INICIAL, 0, false};
	return b;
}


void boton_toggle(Boton* boton)
{
	if(boton->state == true)
	{
		boton->state = false;
	}
	else
	{
		boton->state = true;
	}
}

bool boton_checkPulse(Boton* boton)
{
	bool pulse = false;
	uint32_t read_time = boton->last_read_time;
	uint32_t new_read_time = HAL_GetTick();
	uint32_t difference_read_time = new_read_time - read_time;

	if(difference_read_time > T_REBOTE_MS)
	{
		boton->last_read_time = new_read_time;
		pulse = true;
	}
	return pulse;
}

#endif /* INC_BOTON_H_ */
