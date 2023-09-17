#include "main.h"

/**
 * _printf - Prints string
 * @format: string to print
 *
 * Return: number of characters printed (int);
 */

int _printf(const char *format, ...)
{
	int i = 0, j, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (!format[++i])
				return (-1);

			if (format[i] == 'n')
			{
				*va_arg(args, int *) = count;
				continue;
			}

			j = handle_format(format[i], args);

			if (j == -1)
				return (-1);

			count += j;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
