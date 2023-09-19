#include "main.h"

/**
 * print_hex - Prints integer in hexadecimal (lowercase)
 * @args: Int to print as hex (lowercase)
 * @buffer: buffer
 *
 * Return: length
 */

int print_hex(va_list args, buffer_t *buffer)
{
	char hex[16], tmp;
	unsigned int num, remainder;
	int i = 0, length = 0;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (append_char(buffer, '0'));
	while (num)
	{
		remainder = num % 16;
		if (remainder < 10)
			remainder += 48;
		else
			remainder += 87;
		hex[length] = remainder;
		length++;
		num /= 16;
	}
	hex[length] = '\0';
	_strrev(hex);
	return (append_str(buffer, hex));
}
