#include <stdio.h>

/**
 * main - Prints all the numbers of base 16 in lowercase
 *
 * Return: Always 0.
 */

int main(void)
{
int num;
char i;

for (num = 0; num < 10; num++)
{
putchar((num % 10) + '0');
}

for (i = 'a'; i <= 'f'; i++)
{
putchar(i);
}

putchar('\n');

return (0);
}

