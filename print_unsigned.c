#include "main.h"

/**
 * print_unsigned_helper - Helper function
 * @n: unsigned integer to print
 * @buffer: buffer
 *
 * Return: length
 */

int print_unsigned_helper(unsigned int n, buffer_t *buffer)
{
	if (n / 10)
		print_unsigned_helper(n / 10, buffer);
	return (append_char(buffer, (n % 10) + '0'));
}

/**
 * print_unsigned - Prints an unsigned integer.
 * @args: unsigned integer to print.
 * @buffer: buffer
 *
 * Return: length
 */

int print_unsigned(va_list args, buffer_t *buffer)
{
	return (print_unsigned_helper(va_arg(args, unsigned int), buffer));
}

