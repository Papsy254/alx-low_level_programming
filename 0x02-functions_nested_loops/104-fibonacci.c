#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int first_high, first_low, second_high, second_low, next_high, next_low;
	int i;
	
	first_high = 0;
	first_low = 1;
	second_high = 0;
	second_low = 2;

	printf("%lu, %lu, ", first_low, second_low);

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

	first_high = second_high;
	first_low = second_low;
	second_high = next_high;
	second_low = next_low;

	if (next_high == 0)
	{
	printf("%lu", next_low);
	}
	else
	{
	printf("%lu%010lu", next_high, next_low);
	}

	if (i != 98)
	{
	printf(", ");
	}
	}

	printf("\n");
	return 0;
}
