#include "main.h"

/**
 * more_numbers - prints 10 times the numbers from 0 to 14,
 * followed by a new line.
 */
void more_numbers(void)
{
	int i, j;
	char num[] = "01234567891011121314\n";

	for (i = 0; i < 10; i++)
	{
	for (j = 0; num[j] != '\0'; j++)
	{
	_putchar(num[j]);
	}
	}
}
