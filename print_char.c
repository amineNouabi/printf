#include "main.h"

/**
 * print_char - Prints a char
 * @args: args from va_list
 *
 * Return: 1 on success -1 on error
 */

int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

