#include "main.h"

/**
 * _printf - Prints string
 * @format: string to print
 *
 * Return: number of characters printed (int);
 */

int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;
	buffer_t *buffer;

	if (format == NULL)
		return (-1);

	buffer = create_buffer();
	if (!buffer)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[++i] == 'n')
			{
				*va_arg(args, int *) = count;
				continue;
			}
			if (!format[i] || handle_format(format[i], args, buffer) == -1)
			{
				free_buffer(buffer);
				return (-1);
			}
		}
		else
			append_char(buffer, format[i]);
	}

	if (buffer->length)
		flush_buffer(buffer);

	count = buffer->printed;
	free_buffer(buffer);
	va_end(args);
	return (count);
}
