#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: Pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, word_count;

	if (str == NULL || *str == '\0')
	return (NULL);

	word_count = 0;
	for (i = 0; str[i]; i++)
	{
	if (!isspace(str[i]) && (i == 0 || isspace(str[i - 1])))
	word_count++;
	}

	if (word_count == 0)
	return (NULL);

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
	return (NULL);

	k = 0;
	for (i = 0; str[i]; i++)
	{
	if (!isspace(str[i]))	
	{
	len = 0;
	for (j = i; str[j] && !isspace(str[j]); j++)
	len++;

	words[k] = malloc((len + 1) * sizeof(char));
	if (words[k] == NULL)
	{
	for (i = 0; i < k; i++)
	free(words[i]);
	free(words);
	return (NULL);
	}

	for (j = 0; j < len; j++, i++)
	words[k][j] = str[i];
	words[k][j] = '\0';
	k++;
	}
	}
	words[k] = NULL;

	return (words);
}
