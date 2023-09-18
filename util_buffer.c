#include "main.h"

/**
 * create_buffer - creates a buffer
 *
 * Return: pointer to buffer or NULL on error
 */
buffer_t *create_buffer(void)
{
	buffer_t *buffer = malloc(sizeof(buffer_t));

	if (!buffer)
		return (NULL);

	buffer->buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer->buffer)
	{
		free(buffer);
		return (NULL);
	}

	buffer->length = 0;
	buffer->printed = 0;
	return (buffer);
}

/**
 * free_buffer - frees a buffer
 * @buffer: buffer to free
 * Return: void
 */
void free_buffer(buffer_t *buffer)
{
	free(buffer->buffer);
	free(buffer);
}

/**
 * append_str - appends a character to buffer
 * @buffer: buffer context
 * @str: string to append
 *
 * Return: 1 on success -1 on error
 */
int append_str(buffer_t *buffer, char *str)
{
	int i = 0;

	while (str[i])
	{
		if (buffer->length == BUFFER_SIZE
			|| (buffer->length && buffer->buffer[buffer->length - 1] == '\n'))
		{
			if (flush_buffer(buffer) == -1)
				return (-1);
		}
		buffer->buffer[buffer->length++] = str[i++];
	}
	return (1);
}


/**
 * append_char - appends a character to buffer
 * @buffer: buffer context
 * @c: character to append
 *
 * Return: 1 on success -1 on error
 */
int append_char(buffer_t *buffer, char c)
{
	if (buffer->length == BUFFER_SIZE
		|| (buffer->length && buffer->buffer[buffer->length - 1] == '\n'))
	{
		if (flush_buffer(buffer) == -1)
			return (-1);
	}
	buffer->buffer[buffer->length++] = c;
	return (1);
}

/**
 * flush_buffer - flushes buffer to stdout
 * @buffer: buffer to print
 *
 * Return: 1 on success -1 on error;
 */
int flush_buffer(buffer_t *buffer)
{
	if (write(1, buffer->buffer, buffer->length) < 0)
		return (-1);

	buffer->printed += buffer->length;
	buffer->length = 0;
	return (1);
}
