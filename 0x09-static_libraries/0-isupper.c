#include "main.h"

/**
 * _isupper - uppercase letters
 * @c: char to check
 *
 * Return: If uppercase return 1, else return 0
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	return (1);
	else
	return (0);
}
