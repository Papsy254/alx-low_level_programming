#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char str[] = "Hello, I am learning 1337speak!";
	char *result;

	printf("Original string: %s\n", str);

	result = leet(str);

	printf("Encoded string: %s\n", result);

	return (0);
}
