#include "main.h"

   /**
    * _print - moves a string one place to the left and prints the string
    * @str: string to move
    * @l: size of string
    *
    *  This function prints the string after removing leading zeros.
    *  It also frees the allocated memory for the string.
    */
	void _print(char *str, int l)
{
	int i, j;

	i = j = 0;
	while (i < l)
	{
	if (str[i] != '0')
	j = 1;
	if (j || i == l - 1)
	_putchar(str[i]);
	i++;
	}

	_putchar('\n');
	free(str);
}


/**
* mul - multiplies a char with a string and places the answer into dest
* @n: char to multiply
* @num: string to multiply
* @num_index: last non NULL index of num
* @dest: destination of multiplication
* @dest_index: highest index to start addition
*
* This function multiplies a single digit by a number represented as a string
 * and adds the result to the appropriate position in the destination array.
 * It returns a pointer to the destination array or NULL on failure.
 */
char *mul(char n, char *num, int num_index, char *dest, int dest_index)
{
	int j, k, mul, mulrem, add, addrem;

	mulrem = addrem = 0;
	for (j = num_index, k = dest_index; j >= 0; j--, k--)
	{
	mul = (n - '0') * (num[j] - '0') + mulrem;
	mulrem = mul / 10;
	add = (dest[k] - '0') + (mul % 10) + addrem;
	addrem = add / 10;
	dest[k] = add % 10 + '0';
	}
	for (addrem += mulrem; k >= 0 && addrem; k--)
	{
	add = (dest[k] - '0') + addrem;
	addrem = add / 10;
	dest[k] = add % 10 + '0';
	}
	if (addrem)
	{
	return (NULL);
	}
	return (dest);
}


/**
* check_for_digits - checks the arguments to ensure they are digits
* @av: pointer to arguments
*
* This function checks if all characters in the arguments are digits.
* It returns 0 if all characters are digits, and 1 if any character
* is not a digit.
*/
int check_for_digits(char **av)
{
	int i, j;

	for (i = 1; i < 3; i++)
	{
	for (j = 0; av[i][j]; j++)
	{
	if (av[i][j] < '0' || av[i][j] > '9')
	return (1);
	}
	}
	return (0);
}


/**
* init - initializes a string
* @str: sting to initialize
* @l: length of strinf
*
* This function sets all characters in the string to '0'
* and adds a null terminator.
*/
void init(char *str, int l)
{
	int i;

	for (i = 0; i < l; i++)
	str[i] = '0';
	str[i] = '\0';
}


/**
* main - multiply two numbers
* @argc: number of arguments
* @argv: argument vector
*
* This function checks the validity of the arguments,
* performs the multiplication,
* and prints the result. It exits with status 98 on failure.
* Return: 0 on success, or exit status of 98 on failure.
*/


int main(int argc, char *argv[])
{
	int l1, l2, ln, ti, i;
	char *a;
	char *t;
	char e[] = "Error\n";

	if (argc != 3 || check_for_digits(argv))
	{
	for (ti = 0; e[ti]; ti++)
	_putchar(e[ti]);
	exit(98);
	}
	for (l1 = 0; argv[1][l1]; l1++)
	;
	for (l2 = 0; argv[2][l2]; l2++)
	;
	ln = l1 + l2 + 1;
	a = malloc(ln * sizeof(char));
	if (a == NULL)
	{
	for (ti = 0; e[ti]; ti++)
	_putchar(e[ti]);
	exit(98);
	}
	init(a, ln - 1);
	for (ti = l2 - 1, i = 0; ti >= 0; ti--, i++)
	{
	t = mul(argv[2][ti], argv[1], l1 - 1, a, (ln - 2) - i);
	if (t == NULL)
	{
	for (ti = 0; e[ti]; ti++)
	_putchar(e[ti]);
	free(a);
	exit(98);
	}
	}
	_print(a, ln - 1);
	return (0);
}
