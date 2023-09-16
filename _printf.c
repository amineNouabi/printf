#include "main.h"

/**
 * _printf - Prints string
 * @format: string to print
 *
 * Return: number of characters printed (int);
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int j;
	va_list args;
	int count;

	formats_t arr[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'\0', 0},
	};

	count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			j = 0;
			while (arr[j].c)
			{
				if (format[i + 1] == arr[j].c)
				{
					count += arr[j].f(args);
					i++;
					break;
				}
				j++;
			}
			if (arr[j].c == '\0')
			{
				_putchar('%');
				if (format[i + 1] == '\0')
					return (-1);
				_putchar(format[i + 1]);
				i++;
				count += 2;
			}
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
