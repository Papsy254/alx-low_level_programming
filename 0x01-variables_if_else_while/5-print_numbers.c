#include <stdio.h>

/**
 * main - a program that prints the alphabets in lowercase and uppercase
 *
 * Return: Always 0.
 */

int main(void)
{
char i;

for (i = 'a'; i <= 'z'; i++)
{
if (i != 'e' && i != 'q')
putchar(i);
}

putchar('\n');

return (0);
}

