#include "main.h"

/**
 * print_most_numbers - Prints numbers from 0 to 9, excluding 2 and 4,
 * followed by a new line
 */
void print_most_numbers(void)
{
	char num[] = "01356789";
	char *num_ptr = num;

	while (*num_ptr)
	{
	_putchar(*num_ptr);
	num_ptr++;
	}
}
