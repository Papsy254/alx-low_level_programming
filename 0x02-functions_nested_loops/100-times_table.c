#include <stdio.h>

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The number defining the size of the times table.
 *
 * Description: This function prints the n times table in a formatted
 *              way. If n is greater than 15 or less than 0, the function
 *              does not print anything.
 */
void print_times_table(int n)
{
	int i, j, result;

	if (n < 0 || n > 15)
	return;

	for (i = 0; i <= n; i++)
	{
	for (j = 0; j <= n; j++)
	{
	result = i * j;
	if (j == 0)
	printf("%d", result);
	else
	printf(", %3d", result);
	}
	printf("\n");
	}
}
