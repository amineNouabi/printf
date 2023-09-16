#include "main.h"

/**
 * print_int_helper - Helper function
 * @n: Integer to print
 *
 * Return: length
 */

int print_int_helper(int n)
{
        int num;
        static int len;

        if (n < 0)
        {
                _putchar('-');
                num = -n;
                len++;
        }
        else
                num = n;

        if (num / 10)
                print_int_helper(num / 10);

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
	return (print_int_helper(va_arg(args, int)));
}

