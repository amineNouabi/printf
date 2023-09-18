#include "main.h"
#include <stddef.h>

/**
 * print_str - Prints a string
 * @args: args from va_list
 * @buffer: buffer to print to
 *
 * Return: 1 on success -1 on error
 */

int print_str(va_list args, buffer_t *buffer)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";
	return (append_str(buffer, str));
}

