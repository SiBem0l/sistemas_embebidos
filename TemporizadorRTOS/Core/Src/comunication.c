#include "comunication.h"
#include <string.h>

Comunication comunication_new(UART_HandleTypeDef* huart) {
    Comunication com;
    com.huart = huart;

    // Queue for 5 instructions only
    com.messages_queue = xQueueCreate(5, sizeof(uint8_t) * BUFFER_SIZE);
    return com;
}

void comunication_ready(Comunication* com)
{
    volatile uint8_t* byte = &(com->received_byte);
    HAL_UART_Receive_IT(com->huart, (uint8_t*)byte, 1);
}

void comunication_send(Comunication* com, const char* message)
{
    HAL_UART_Transmit(com->huart, (uint8_t*)message, strlen(message), COMUNICATION_TIMEOUT);
}

void comunication_store_byte_isr(Comunication* com, BaseType_t* xHigherPriorityTaskWoken)
{
    static uint8_t buffer[BUFFER_SIZE];
    static int size = 0;

    buffer[size] = com->received_byte;
    size++;

    // Check if the message is ready to be processed
    if (com->received_byte == '\n' || com->received_byte == '\0' || size >= BUFFER_SIZE)
    {
        if (size < BUFFER_SIZE)
        {
            buffer[size] = '\0';
        }
        else
        {
            buffer[BUFFER_SIZE - 1] = '\0';
        }

        // Send the message to the queue to later be processed
        xQueueSendFromISR(com->messages_queue, (void*)buffer, xHigherPriorityTaskWoken);

        // Reset buffer
        size = 0;
    }
}
