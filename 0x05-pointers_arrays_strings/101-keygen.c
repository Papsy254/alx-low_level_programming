#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: Always 0
 */
int main(void)
{
	char password[84];
	int i, sum = 0, target_sum = 2772;

	srand(time(NULL));

	for (i = 0; i < 83; i++)
	{
	password[i] = (rand() % 94) + 33;
	sum += password[i];
	putchar(password[i]);
	if (sum >= target_sum)
	{
	sum -= password[i];
	break;
	}
	}

	password[i] = target_sum - sum;
	putchar(password[i]);
	putchar('\n');

	return 0;
}

