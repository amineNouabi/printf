#include "main.h"

/**
 * print_hex_upper - Prints integer in hexadecimal (uppercase)
 * @args: Int to print as hex (uppercase)
 * @buffer: buffer
 *
 * Return: length
 */

int print_hex_upper(va_list args, buffer_t *buffer)
{
	char hex[16], tmp;
	unsigned int num, remainder;
	int i = 0, length = 0;

	num = va_arg(args, unsigned int);

	while (num)
	{
		remainder = num % 16;
		if (remainder < 10)
			remainder += 48;
		else
			remainder += 55;
		hex[length] = remainder;
		length++;
		num /= 16;
	}
	hex[length] = '\0';

	for (i = 0; i < (length / 2); i++)
	{
		tmp = hex[i];
		hex[i] = hex[length - i - 1];
		hex[length - i - 1] = tmp;
	}
	return (append_str(buffer, hex));
}
