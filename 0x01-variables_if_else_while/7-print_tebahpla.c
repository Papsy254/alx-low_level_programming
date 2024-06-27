#include <stdio.h>

/**
 * main - a program that prints the lowercase alphabets in lowercase
 *
 * Return: Always 0.
 */

int main(void)
{
char i;

for (i = 'z'; i >= 'a'; i--)
{
putchar(i);
}

putchar('\n');

return (0);
}

