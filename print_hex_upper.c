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
	char hex[16];
	unsigned int num, remainder;
	int length = 0;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (append_char(buffer, '0'));
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
	_strrev(hex);
	return (append_str(buffer, hex));
}
