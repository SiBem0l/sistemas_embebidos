#include <string.h>
#include "buffer.h"


Buffer buffer_new()
{
	return (Buffer){"", 0};
}

bool buffer_is_full(Buffer* buffer)
{
	return buffer->data_size >= BUFFER_SIZE;
}

void buffer_clear(Buffer* buffer)
{
	buffer->data[0] = '\0';
	buffer->data_size = 0;
}

void buffer_store_byte(Buffer* buffer, char byte)
{
    if(buffer_is_full(buffer))
    {
        buffer_clear(buffer);
    }
	buffer->data[buffer->data_size] = byte;
	buffer->data_size++;
}

char* buffer_get_data(Buffer* buffer)
{
	return (char*)buffer->data;
}
