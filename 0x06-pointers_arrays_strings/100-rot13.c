#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 cipher
 * @n: Input string to encode
 * Return: Encoded string
 */
char *rot13(char *n)
{
	char *start = n;
	 char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i;

	while (*n != '\0')
	{
	for (i = 0; i < 52; i++)
	{
	if (*n == alphabet[i])
	{
	*n = rot13[i];
	break;
	}
	}
	n++;
	}

	return (start);
}
