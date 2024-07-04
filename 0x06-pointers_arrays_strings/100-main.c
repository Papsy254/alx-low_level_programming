#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char s[] = "ROT13 (\"rotate by 13 places\", sometimes hyphenated ROT-13) "
		"is a simple letter substitution cipher.\n";
	char *p;

	printf("Original string:\n%s\n", s);

	p = rot13(s);
	printf("Encoded string:\n%s\n", p);

	return (0);
}
