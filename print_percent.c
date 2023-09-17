#include "main.h"

/**
 * print_percent - Prints % sign
 * @args: args from va_list (unused)
 *
 * Return: 1 on success -1 on error
 */

int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}
