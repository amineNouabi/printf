#include "main.h"
#include <stddef.h>

/**
 * print_str - Prints a string
 * @args: args from va_list
 *
 * Return: length (int)
 */

int print_str(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);
	char *null_str = "(null)";

	if (str == NULL)
	{
		while (null_str[len])
		{
			_putchar(null_str[len]);
			len++;
		}
		return (len);
	}

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}

