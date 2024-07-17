#include <stdlib.h>
#include <ctype.h>
#include "main.h"

/**
 * word_len - calculates the length of a word
 * @str: the string to evaluate
 *
 * Return: length of the word
 */
int word_len(char *str)
{
	int len = 0;

	while (str[len] && !isspace(str[len]))
	len++;
	return (len);
}

/**
 * count_words - counts the number of words in a string
 * @str: the string to evaluate
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
	if (!isspace(str[i]) && (i == 0 || isspace(str[i - 1])))
	count++;
	}
	return (count);
}

/**
 * free_words - frees memory allocated for words
 * @words: array of words
 * @count: number of words to free
 */
void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
	free(words[i]);
	free(words);
}

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

	word_count = count_words(str);
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
	len = word_len(str + i);
	words[k] = malloc((len + 1) * sizeof(char));
	if (words[k] == NULL)
	{
	free_words(words, k);
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
