#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 cipher
 * @n: Input string to encode
 * Return: Encoded string
 */
char *rot13(char *n)
{
	char *start = n;

	while (*n != '\0')
	{
	if ((*n >= 'a' && *n <= 'm') || (*n >= 'A' && *n <= 'M'))
	*n += 13;
	else if ((*n >= 'n' && *n <= 'z') || (*n >= 'N' && *n <= 'Z'))
	*n -= 13;

	n++;
	}

	return (start);
}
