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

/**
 * print_str - Prints a string
 * @args: args from va_list
 * @buffer: buffer to print to
 *
 * Return: 1 on success -1 on error
 */

int print_str_rev(va_list args, buffer_t *buffer)
{
	int status;
	char *str = _strdup(va_arg(args, char *));

	if(!str)
		return (-1);
	_strrev(str);
	status = append_str(buffer, str);
	free(str);
	return (status);
}

