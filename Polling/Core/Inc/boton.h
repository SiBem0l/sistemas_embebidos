#ifndef BOTON_H
#define BOTON_H

#include <stdbool.h>
#include "main.h"

// Tiempo de espera por rebote en el pulsador
const static int T_REBOTE_MS = 10;
// Cual es el estado inicial del boton sin apretar
const static int ESTADO_VALIDO_INICIAL = GPIO_PIN_SET;


typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
	GPIO_PinState estado_boton;
} Boton;

Boton boton_new(GPIO_TypeDef* port, uint16_t pin)
{
	Boton b = {port, pin, ESTADO_VALIDO_INICIAL};
	return b;
}

bool boton_hayPulsacion(Boton* ptr_boton)
{
    bool nueva_pulsacion = false;

    GPIO_PinState lectura1;
    GPIO_PinState lectura2;

    /* Primera lectura del pulsador */
    lectura1 = HAL_GPIO_ReadPin(ptr_boton->port, ptr_boton->pin);

    /* Solo se realiza debounce ante un posible cambio */
    if (lectura1 != ptr_boton->estado_boton)
    {
    	// Espero el tiempo de margen para el rebote del pulsador
    	HAL_Delay(T_REBOTE_MS);

        // Vuelvo a tomar una lectura
        lectura2 = HAL_GPIO_ReadPin(ptr_boton->port, ptr_boton->pin);

        // Si ambas lecturas son iguales la lectura no es ruido
        if (lectura2 == lectura1)
        {
            // Si pasa de SET a RESET hay un flanco negativo
            if ((ptr_boton->estado_boton == GPIO_PIN_SET) &&
                (lectura1 == GPIO_PIN_RESET))
            {
                nueva_pulsacion = true;
            }

            // Actualizo el estado del boton
            ptr_boton->estado_boton = lectura2; // o lectura1
        }
    }
    return nueva_pulsacion;
}

#endif
