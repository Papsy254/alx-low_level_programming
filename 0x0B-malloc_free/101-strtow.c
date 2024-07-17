#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words in.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int count = 0, in_word = 0;

	while (*str)
	{
	if (*str == ' ')
	in_word = 0;
	else if (in_word == 0)
	{
	in_word = 1;
	count++;
	}
	str++;
	}
	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to an array of strings (words), or NULL on failure.
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
	return (NULL);

	int num_words = count_words(str);
	if (num_words == 0)
	return (NULL);

	char **matrix = malloc((num_words + 1) * sizeof(char *));
	if (matrix == NULL)
	return (NULL);

	int i = 0, start = 0, k = 0;
	int len = strlen(str);

	while (i <= len)
	{
	if (str[i] == ' ' || str[i] == '\0')
	{
	if (start < i)
	{
	int word_len = i - start;
	char *word = malloc((word_len + 1) * sizeof(char));
	if (word == NULL)
	{
	for (int j = 0; j < k; j++)
	free(matrix[j]);
	free(matrix);
	return NULL;
	}
	strncpy(word, &str[start], word_len);
	word[word_len] = '\0';
	matrix[k++] = word;
	}
	start = i + 1;
	}
	i++;
	}

	matrix[k] = NULL;
	return matrix;
}
