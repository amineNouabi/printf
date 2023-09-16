#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stddef.h>

/**
 * struct formats - Defines each format specifier char with its function
 * @c: format specifier char
 * @f: Relevant function to format specifier char
 */

typedef struct formats
{
	char c;
	int (*f)(va_list);
} formats_t;


int _printf(const char *format, ...);
int handle_format(char c, va_list args);
int _putchar(char c);
int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif
