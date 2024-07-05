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
	int i, sum = 0;
	char password[84];

	srand(time(NULL));

	for (i = 0; i < 84; i++)
	{
	password[i] = (rand() % 94) + 33;
	sum += password[i];
	putchar(password[i]);
	if (sum > 2772)
	{
	sum -= password[i];
	break;
	}
	}
	password[i] = 2772 - sum;
	putchar(password[i]);
	putchar('\n');

	return (0);
}
