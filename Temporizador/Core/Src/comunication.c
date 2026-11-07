#include <string.h>
#include "comunication.h"


Comunication comunication_new(UART_HandleTypeDef* huart)
{
	Comunication comunication = {buffer_new(), '\0', huart};
	return comunication;
}

void comunication_ready(Comunication* com)
{
	volatile char* byte = &(com->recived_byte);
	HAL_UART_Receive_IT(com->huart, (uint8_t*)byte, 1);
}

void comunication_send(Comunication* com, char* message)
{
	// Transfer in UART the message
	HAL_UART_Transmit(com->huart, (uint8_t*)message, strlen(message), TIMEOUT);
}

void comunication_clear_buffer(Comunication* com)
{
	buffer_clear(&(com->buffer));
}

void comunication_store_byte(Comunication* com)
{
	buffer_store_byte(&(com->buffer), com->recived_byte);
}

char* comunication_get_data(Comunication* com)
{
	return buffer_get_data(&(com->buffer));
}

