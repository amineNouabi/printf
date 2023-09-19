#include "main.h"

/**
 * print_s - prints the string and non printable chars
 * @args: string to print
 * @buffer: buffer
 *
 * Return: 0
 */

int print_s(va_list args, buffer_t *buffer)
{
	char *s, *hex = "0123456789ABCDEF", tmp[5];
	int i;

	s = va_arg(args, char *);

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 32 || s[i] > 126)
		{
			tmp[0] = '\\';
			tmp[1] = 'x';
			tmp[2] = hex[s[i] / 16];
			tmp[3] = hex[s[i] % 16];
			tmp[4] = '\0';
			append_str(buffer, tmp);
		}
		else
			append_char(buffer, s[i]);
	}
	return (0);
}
