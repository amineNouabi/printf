#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024


/**
 * struct buffer - Defines a new type struct buffer
 * @buffer: Pointer to a char buffer
 * @length: Length of the buffer
 * @printed: Number of chars printed
 */
typedef struct buffer
{
	char *buffer;
	unsigned int length;
	unsigned int printed;

} buffer_t;

/**
 * struct formats - Defines each format specifier char with its function
 * @c: format specifier char
 * @f: Relevant function to format specifier char
 */
typedef struct formats
{
	char c;
	int (*f)(va_list, buffer_t *);
} formats_t;



int _printf(const char *format, ...);
int handle_format(char, va_list, buffer_t *);
int print_char(va_list, buffer_t *);
int print_str(va_list, buffer_t *);
int print_percent(va_list, buffer_t *);
int print_int(va_list, buffer_t *);
int print_binary(va_list, buffer_t *);
int print_octal(va_list, buffer_t *);
int print_unsigned(va_list, buffer_t *);
int print_hex(va_list, buffer_t *);
int print_hex_upper(va_list, buffer_t *);
int print_s(va_list, buffer_t *);
int print_str_rev(va_list, buffer_t *);
int print_str_rot13(va_list, buffer_t *);


/********  Buffer ************/
buffer_t *create_buffer(void);
void free_buffer(buffer_t *);
int flush_buffer(buffer_t *);
int append_str(buffer_t *, char *);
int append_char(buffer_t *, char);

/******** String ************/
int _strlen(char *);
char *_strdup(char *);
void _strrev(char *);
void _strrot13(char *str);

#endif /* PRINTF_H */
