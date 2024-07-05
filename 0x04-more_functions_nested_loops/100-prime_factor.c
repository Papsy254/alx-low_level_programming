#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	long number = 612852475143;
	long largest_prime_factor = -1;
	long i;

	while (number % 2 == 0) {
	largest_prime_factor = 2;
	number /= 2;
	}

	for (i = 3; i <= sqrt(number); i += 2) {
	while (number % i == 0) {
	largest_prime_factor = i;
	number /= i;
	}
	}

	if (number > 2)
	largest_prime_factor = number;

	printf("%ld\n", largest_prime_factor);
	return 0;
}
