#include <stdio.h>
#include "main.h"


/**
 * main - Entry point of the program to check endianness
 *
 * Return: 0 on success
 */

int main(void)
{
	int n;

	n = get_endianness();
	if (n != 0)
	{
	printf("Little Endian\n");
	}
	else
	{
	printf("Big Endian\n");
	}
	return (0);
}
