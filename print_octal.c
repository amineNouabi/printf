#include "main.h"

/**
 * print_octal - Prints integer in octal
 * @args: int to print in octal
 * @buffer: buffer
 *
 * Return: length
 */

int print_octal(va_list args, buffer_t *buffer)
{
	char octal[32], tmp;
	int length = 0, i;
	unsigned int n;

	n = va_arg(args, unsigned int);

	if (n == 0)
		return(append_char(buffer, '0'));
	while (n)
	{
		octal[length] = (n % 8) + '0';
		n /= 8;
		length++;
	}
	octal[length] = '\0';
	for (i = 0; i < (length / 2); i++)
	{
		tmp = octal[i];
		octal[i] = octal[length - i - 1];
		octal[length - i - 1] = tmp;
	}
	return (append_str(buffer, octal));
}
