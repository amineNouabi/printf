#include "main.h"
#include <stddef.h>

/**
 * print_str - Prints a string
 * @args: args from va_list
 *
 * Return: length (int) on success -1 on error
 */

int print_str(va_list args, buffer_t *buffer)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	append_str(buffer, str);
	return (len);
}

