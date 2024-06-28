#include <stdio.h>
/**
 * print_fibonacci_98 - prints the first 98 Fibonacci numbers
 *
 * Return: void
 */
void print_fibonacci_98(void)
{
	unsigned long a = 1, b = 2;
	unsigned long a_high, a_low, b_high, b_low;
	unsigned long split = 1000000000;
	int i;

	printf("%lu, %lu", a, b);
	for (i = 3; i <= 98; i++)
	{
	if (b > split)
	{
	a_high = a / split;
	a_low = a % split;
	b_high = b / split;
	b_low = b % split;

	unsigned long next_high = a_high + b_high + (a_low + b_low) / split;
	unsigned long next_low = (a_low + b_low) % split;

	printf(", %lu%09lu", next_high, next_low);

	a = b;
	a_high = b_high;
	a_low = b_low;
	b = next_high * split + next_low;
	}
	else
	{
	unsigned long next = a + b;

	printf(", %lu", next);
	a = b;
	b = next;
	}
	}
	printf("\n");
}

/**
 * main - entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_fibonacci_98();
	return (0);
}
