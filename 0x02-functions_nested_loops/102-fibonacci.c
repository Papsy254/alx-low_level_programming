#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	long int first = 1, second = 2, next;

	printf("%ld, %ld", first, second);

	for (count = 2; count < 50; count++)
	{
	next = first + second;
	first = second;
	second = next;

	printf(", %ld", next);
	}

	printf("\n");

	return (0);
}
