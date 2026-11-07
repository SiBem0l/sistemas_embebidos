#ifndef BUFFER_H
#define BUFFER_H

#include <stdbool.h>

#define BUFFER_SIZE 20

typedef struct
{
	volatile char data[BUFFER_SIZE];
	volatile int data_size;
} Buffer;

Buffer buffer_new();

bool buffer_is_full(Buffer* buffer);
void buffer_clear(Buffer* buffer);

void buffer_store_byte(Buffer* buffer, char byte);
char* buffer_get_data(Buffer* buffer);

#endif
