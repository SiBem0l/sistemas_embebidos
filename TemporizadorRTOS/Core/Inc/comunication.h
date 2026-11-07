#ifndef COMUNICATION_H
#define COMUNICATION_H

#include "main.h"

// 1. INCLUSIONES NECESARIAS
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include <stdint.h>
#include <stdbool.h>


#define COMUNICATION_TIMEOUT     1000 // [ms]
#define BUFFER_SIZE 64   // Size of the QUEUE

typedef struct
{
    UART_HandleTypeDef* huart;
    QueueHandle_t messages_queue;
    volatile uint8_t received_byte;
} Comunication;


Comunication comunication_new(UART_HandleTypeDef* huart);
void comunication_ready(Comunication* com);
void comunication_send(Comunication* com, const char* message);
uint16_t comunication_get_data(Comunication* com, char* out_buffer, uint16_t max_length);
void comunication_store_byte_isr(Comunication* com, BaseType_t* xHigherPriorityTaskWoken);

#endif // COMUNICATION_H
