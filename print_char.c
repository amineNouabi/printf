#include "main.h"

/**
 * print_char - Prints a char
 * @args: args from va_list
 * @buffer: buffer to print to
 *
 * Return: 1 on success -1 on error
 */

int print_char(va_list args, buffer_t *buffer)
{
	return (append_char(buffer, va_arg(args, int)));
}

