#include "main.h"

/**
 * get_length - Calculates the length of a string
 * @str: Input string
 * Return: Length of the string
 */
int get_length(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	len++;
	return (len);
}

/**
 * reverse_string - Reverses a string in place
 * @str: String to reverse
 * @len: Length of the string
 */
void reverse_string(char *str, int len)
{
	int i, j;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
	char temp = str[i];

	str[i] = str[j];
	str[j] = temp;
	}
}

/**
 * infinite_add - Adds two numbers stored as strings
 * @n1: First number string
 * @n2: Second number string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 * Return: Pointer to the result string, or 0 if result cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = get_length(n1);
	int len2 = get_length(n2);
	int carry = 0;
	int i = len1 - 1;
	int j = len2 - 1;
	int k = 0;

	if (len1 + 1 > size_r || len2 + 1 > size_r)

	return (0);

	while (i >= 0 || j >= 0 || carry > 0)
	{
	int sum = carry;

	if (i >= 0)
	sum += n1[i] - '0';
	if (j >= 0)
	sum += n2[j] - '0';

	r[k++] = (sum % 10) + '0';
	carry = sum / 10;

	i--;
	j--;
	}

	r[k] = '\0';

	reverse_string(r, k);

	return (r);
}
