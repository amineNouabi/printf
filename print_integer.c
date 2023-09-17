#include "main.h"

/**
 * print_int_helper - Helper function
 * @n: Integer to print
 * @len: Length
 *
 * Return: length
 */

int print_int_helper(int n, int len)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		len++;
	}
	else
		num = n;

	if (num / 10)
		len = print_int_helper(num / 10, len);

	_putchar((num % 10) + '0');
	return (++len);

}

/**
 * print_int - Prints an integer.
 * @args: Integer to print.
 * Return: length
 */

int print_int(va_list args)
{
	return (print_int_helper(va_arg(args, int), 0));
}

