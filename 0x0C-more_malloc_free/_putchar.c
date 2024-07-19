#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to print.
 *
 * Return: On success, returns the character written.
 *         On error, returns -1 and sets errno.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}
