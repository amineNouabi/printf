#include "main.h"

/**
 * _strlen - calculates length of a string
 * @s: String
 * Return: Number of characters in string
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count++])
		;

	return (count - 1);
}

/**
 * _strrev - reverses string
 * @s: String
 * Return: void
 */
void _strrev(char *s)
{
	int length = 0;
	int i;

	while (s[length++])
		;
	length--;

	for (i = 0; i < length / 2; i++)
	{
		char temp = s[i];

		s[i] = s[length - i - 1];
		s[length - 1 - i] = temp;
	}
}


/**
 * _strdup - allocates memory for a copy of a string
 * @s: String
 * Return: Pointer to new string or NULL
 */
char *_strdup(char *s)
{
	int len, i;
	char *dest;

	if (!s)
		return (0);

	len = _strlen(s);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);

	i = -1;
	while (s[++i])
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strrot13 - encodes String to ROT13
 * @str: String to encode
 * Return: void
 */
void _strrot13(char *str)
{
	int i = -1, j;
	char *l = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *n = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (str[++i])
	{
		j = 0;
		while (l[j])
		{
			if (str[i] == l[j])
			{
				str[i] = n[j];
				break;
			}
			j++;
		}
	}
}
