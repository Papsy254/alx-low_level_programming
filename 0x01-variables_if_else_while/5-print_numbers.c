#include <stdio.h>

/**
 * main - a program that prints the alphabets in lowercase and uppercase
 *
 * Return: Always 0.
 */

int main(void)
{
char i;

for (i = 0; i < 10; i++)
{
putchar(i + '0');
}

putchar('\n');

return (0);
}

