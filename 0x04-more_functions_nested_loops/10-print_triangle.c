#include "main.h"

/**
 * print_triangle - prints a triangle of '#'
 * characters, followed by a new line.
 * @size: size of the triangle
 *
 * If size is 0 or less, it prints only a new line.
 */
void print_triangle(int size)
{
	int row, column;

	if (size <= 0)
	{
	_putchar('\n');
	return;
	}

	for (row = 1; row <= size; row++)
	{
	for (column = 1; column <= size; column++)
	{
	if (column <= size - row)
	_putchar(' ');
	else
	_putchar('#');
	}
	_putchar('\n');
	}
}
