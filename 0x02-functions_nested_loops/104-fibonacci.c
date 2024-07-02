#include <stdio.h>

void print_fibonacci(unsigned long int first_high,
		unsigned long int first_low,
		unsigned long int second_high,
		unsigned long int second_low);
void print_number(unsigned long int high,
		unsigned long int low);

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int first_high = 0;
	unsigned long int first_low = 1;
	unsigned long int second_high = 0;
	unsigned long int second_low = 2;

	printf("%lu, %lu, ", first_low, second_low);

	print_fibonacci(first_high, first_low,
			second_high, second_low);

	printf("\n");
	return (0);
}

/**
 * print_fibonacci - Prints the next 96 Fibonacci numbers
 * @first_high: High part of the first Fibonacci number
 * @first_low: Low part of the first Fibonacci number
 * @second_high: High part of the second Fibonacci number
 * @second_low: Low part of the second Fibonacci number
 */
void print_fibonacci(unsigned long int first_high,
		unsigned long int first_low,
		unsigned long int second_high,
		unsigned long int second_low)
{
	unsigned long int next_high, next_low;
	int i;

	for (i = 3; i <= 98; i++)
	{
	if (first_low + second_low > 9999999999)
	{
	next_low = (first_low + second_low) % 10000000000;
	next_high = first_high + second_high + 1;
	}
	else
	{
	next_low = first_low + second_low;
	next_high = first_high + second_high;
	}

	print_number(next_high, next_low);

	if (i != 98)
	{
	printf(", ");
	}

	first_high = second_high;
	first_low = second_low;
	second_high = next_high;
	second_low = next_low;
	}
}

/**
 * print_number - Prints a Fibonacci number with high and low parts
 * @high: High part of the number
 * @low: Low part of the number
 */
void print_number(unsigned long int high,
		unsigned long int low)
{
	if (high > 0)
	{
	printf("%lu%010lu", high, low);
	}
	else
	{
	printf("%lu", low);

	}
}
