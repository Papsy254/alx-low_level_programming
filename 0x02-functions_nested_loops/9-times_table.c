#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
 */
void times_table(void)
{
	int row, col, product;

	for (row = 0; row < 10; row++)
	{
	for (col = 0; col < 10; col++)
	{
	product = row * col;

	if (col == 0)
	{
	_putchar(product + '0');
	}
	else if (product < 10)
	{
	_putchar(',');
	_putchar(' ');
	_putchar(' ');
	_putchar(product + '0');
	}
	else
	{
	_putchar(',');
	_putchar(' ');
	_putchar((product / 10) + '0');
	_putchar((product % 10) + '0');
	}
	}
	_putchar('\n');
	}
}
