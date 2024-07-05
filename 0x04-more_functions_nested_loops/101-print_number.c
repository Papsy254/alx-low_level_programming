#include "main.h"

/**
 * print_number - Prints an integer using _putchar
 * @n: The integer to be printed
 *
 * Description: Prints the integer 'n' using _putchar function.
 * Handles negative integers by printing '-' first and then the absolute value.
 * Does not use long, arrays, pointers, or hard-coded special values.
 */
void print_positive(int n);

void print_number(int n)
{
	if (n < 0)
	{
	_putchar('-');
	n = -n;
	}

	if (n == 0)
	{
	_putchar('0');
	return;
	}

	print_positive(n);
}

/**
 * print_positive - Helper function to print positive integers recursively
 * @n: The positive integer to be printed
 *
 * Description: Recursively divides 'n' by 10 to extract and print each digit.
 * Uses _putchar to print each digit as it unwinds the recursion.
 */
void print_positive(int n)
{
	if (n == 0)
	return;

	print_positive(n / 10);
	_putchar(n % 10 + '0');
}
