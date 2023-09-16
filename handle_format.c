#include "main.h"

/**
 * handle_format - selects the correct function to format the input
 * @c: character that specifies the operation to perform
 * @args: list of arguments
 * Return: number of characters printed
 */
int handle_format(char c, va_list args)
{
	int i = -1, j = 0, count = 0;

	formats_t formatters[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'\0', 0},
	};

	while (formatters[++i].c)
		if (formatters[i].c == c)
		{
			j = formatters[i].f(args);
			if (j == -1)
				return (-1);

			count += j;
			break;
		}

	if (formatters[i].c == '\0')
	{
		_putchar('%');
		_putchar(c);
		count += 2;
	}

	return (count);
}
