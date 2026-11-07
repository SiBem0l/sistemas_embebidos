#ifndef OUTPUT_H
#define OUTPUT_H

#include "main.h"

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
} Output;

Output output_new(GPIO_TypeDef* port, uint16_t pin)
{
	return (Output){port,pin};
}

#endif
