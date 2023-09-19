#include "main.h"

/**
 * print_hexa_upper - prints unsigned int in hexadecimal with uppercase letters
 * @args: arguments list.
 * @buffer: buffer.
 * 
 * Return: 1 if success 0 if error.
 */
int print_hexa_upper(va_list args, buffer_t *buffer)
{
	char *base = "0123456789ABCDEF", str[32];
	unsigned int n, i;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (append_char(buffer, '0'));

	i = 0;
	while (n)
	{
		str[i++] = base[n % 16];
		n /= 16;
	}
	str[i] = '\0';
	_strrev(str);

	return (append_str(buffer, str));
}

/**
 * print_hexa_upper - prints unsigned int in hexadecimal with lowercase letters
 * @args: arguments list.
 * @buffer: buffer.
 * 
 * Return: 1 if success 0 if error.
 */
int print_hexa_lower(va_list args, buffer_t *buffer)
{
	char *base = "0123456789abcdef", str[32];
	unsigned int n, i;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (append_char(buffer, '0'));

	i = 0;
	while (n)
	{
		str[i++] = base[n % 16];
		n /= 16;
	}
	str[i] = '\0';
	_strrev(str);

	return (append_str(buffer, str));
}
