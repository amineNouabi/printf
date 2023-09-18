#include "main.h"

/**
 * print_int_helper - Helper function
 * @n: Integer to print
 * @buffer: buffer
 *
 * Return: length
 */

int print_int_helper(int n, buffer_t *buffer)
{
	unsigned int num;

	if (n < 0)
	{
		append_char(buffer, '-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		print_int_helper(num / 10, buffer);
	append_char(buffer, (num % 10) + '0');
	return (1);
}

/**
 * print_int - Prints an integer.
 * @args: Integer to print.
 * @buffer: buffer
 *
 * Return: length
 */

int print_int(va_list args, buffer_t *buffer)
{
	return (print_int_helper(va_arg(args, int), buffer));
}

