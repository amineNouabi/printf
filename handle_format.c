#include "main.h"

/**
 * handle_format - selects the correct function to format the input
 * @c: character that specifies the operation to perform
 * @args: list of arguments
 * @buffer: buffer to store output
 * Return: 1 on success, -1 on error
 */
int handle_format(char c, va_list args, buffer_t *buffer)
{
	int i = -1;

	formats_t formatters[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'i', print_int},
		{'d', print_int},
		{'\0', 0},
	};

	while (formatters[++i].c)
		if (formatters[i].c == c)
			return (formatters[i].f(args, buffer));
	return (append_char(buffer, '%') + append_char(buffer, c) == 2 ? 1 : -1);
}
