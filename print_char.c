#include "main.h"

/**
 * print_char - Prints a char
 * @args: args from va_list
 *
 * Return: 1
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}
