#include <stdio.h>
#include <ctype.h>

/**
 * print_buffer - Prints the content of a buffer in a specified format
 * @b: Buffer to print
 * @size: Size of the buffer
 */
void print_buffer(char *b, int size)
{
	int offset, i, j;

	if (size <= 0)
	{
	printf("\n");
	return;
	}

	for (offset = 0; offset < size; offset += 10)
	{
	printf("%08x: ", offset);

	for (i = 0; i < 10; i++)
	{
	if (offset + i < size)
	printf("%02x", (unsigned char)b[offset + i]);
	else
	printf("  ");
	if (i % 2)
	printf(" ");
	}

	for (j = 0; j < 10 && offset + j < size; j++)
	{
	if (isprint((unsigned char)b[offset + j]))
	printf("%c", b[offset + j]);
	else
	printf(".");
	}

	printf("\n");
	}
}
