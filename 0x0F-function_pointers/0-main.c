#include <stdio.h>
#include "function_pointers.h"

/* Function prototype */
int sum_them_all(const unsigned int n, ...);

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int sum;

	sum = sum_them_all(2, 98, 1024);
	printf("%d\n", sum);
	sum = sum_them_all(4, 98, 1024, 402, -1024);
	printf("%d\n", sum);
	return (0);
}
