#include "main.h"

/**
 * print_pointer - Prints a pointer
 * @args: args from va_list
 * @buffer: buffer to print to
 *
 * Return: 1 on success -1 on error
 */
int print_pointer(va_list args, buffer_t *buffer)
{
	unsigned int i;
	unsigned long int n;
	char *base = "0123456789abcdef", str[32];
	void *arg = va_arg(args, void *);

	if (!arg)
		return (-1);
	n = (unsigned long int)arg;

	i = 0;
	while (n)
	{
		str[i++] = base[n % 16];
		n /= 16;
	}
	str[i++] = 'x';
	str[i++] = '0';
	str[i] = '\0';
	_strrev(str);

	return (append_str(buffer, str));
}
