#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    int n;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Len: %d len2: %d\n", len, len2);
    len = _printf("Character:[%c]\n", 'H');
    len2 = printf("Character:[%c]\n", 'H');
    printf("Len: %d, len2: %d\n",len, len2); 
    len =_printf("String:[%s]\n", "I am a string !");
    len2 = printf("String:[%s]\n", "I am a string !");
    printf("len: %d len2: %d\n", len, len2);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    printf("len: %d, len2: %d\n", len, len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
