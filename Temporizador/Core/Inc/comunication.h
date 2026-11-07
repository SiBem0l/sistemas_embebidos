#ifndef COMUNICATION_H
#define COMUNICATION_H

#include "main.h"
#include "buffer.h"

// Time to wait for transfer response
#define TIMEOUT 1000 // [ms]

typedef struct
{
	Buffer buffer;
	volatile char recived_byte;
	UART_HandleTypeDef* huart;
} Comunication;

Comunication comunication_new(UART_HandleTypeDef* huart);

void comunication_ready(Comunication* com);
void comunication_send(Comunication* com, char* message);

// Buffer handling
char* comunication_get_data(Comunication* com);
void comunication_store_byte(Comunication* com);
void comunication_clear_buffer(Comunication* com);

#endif
