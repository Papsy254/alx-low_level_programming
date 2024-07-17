#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_positive_number - Checks if a string is a positive number.
 * @str: The string to check.
 *
 * Return: 1 if the string is a positive number, 0 otherwise.
 */
int is_positive_number(char *str)
{
	while (*str)
	{
	if (!isdigit(*str))
	return (0);
	str++;
	}
	return (1);
}

/**
 * main - Adds positive numbers.
 * @argc: The number of command line arguments.
 * @argv: An array of command line arguments.
 *
 * Return: 0 if successful, 1 if an error occurs.
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
	printf("0\n");
	return (0);
	}

	for (i = 1; i < argc; i++)
	{
	if (!is_positive_number(argv[i]))
	{
	printf("Error\n");
	return (1);
	}
	sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
