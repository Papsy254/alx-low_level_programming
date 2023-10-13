#include <stdio.h>
/**
 * main - A C program that prints the size of various types on the computer it is compiled and run on.
 * Return 0 (Success)
 */
int main(void)
{

	char a;
	int b;
	long c;
	long long d;
	float f;
  
printf("Size of a char: %lu 1 byte (s)\n", sizeof(char));
printf("Size of an int: %lu 4 byte (s)\n", sizeof(int));
printf("Size of a long int: %lu 4 byte (s)\n", sizeof(long int));
printf("Size of a long long int: %lu 8 byte (s)\n", sizeof(long long int));
printf("Size of a float: %lu 4 byte (s)\n", sizeof(float));
return (0);
}
