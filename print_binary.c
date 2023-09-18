#include "main.h"

/**
 * print_binary - Prints integer in binary
 * @args: unsigned int to print as binary
 * @buffer: buffer
 *
 * Return: length
 */

int print_binary(va_list args, buffer_t *buffer)
{
	char binary[256], tmp;
	int length = 0, i;
	unsigned int n;

	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		return (append_char(buffer, '0'));
	}
	while (n != 0)
	{
		if (n % 2 == 0)
			binary[length] = '0';
		else
			binary[length] = '1';
		n /= 2;
		length++;
	}
	binary[length] = '\0';
	for (i = 0; i < (length / 2); i++)
	{
		tmp = binary[i];
		binary[i] = binary[length - i - 1];
		binary[length - i - 1] = tmp;
	}
	return (append_str(buffer, binary));
}
