#include <stdio.h>
#include <stdlib.h>

/**
 * main - Calculates the minimum number of coins to make change for an amount
 * of money.
 * @argc: The number of command line arguments.
 * @argv: An array of command line arguments.
 *
 * Return: 0 if successful, 1 if an error occurs.
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;
	int coin_values[] = {25, 10, 5, 2, 1};
	int i;

	if (argc != 2)
	{
	printf("Error\n");
	return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
	printf("0\n");
	return (0);
	}

	for (i = 0; i < 5 && cents > 0; i++)
	{
	while (cents >= coin_values[i])
	{
	cents -= coin_values[i];
	coins++;
	}
	}

	printf("%d\n", coins);
	return (0);
}
