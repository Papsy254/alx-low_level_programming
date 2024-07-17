#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *str);
char **strtow(char *str);

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

char **strtow(char *str)
{
	int num_words;
	char **matrix;
	int i = 0, start = 0, k = 0;
	int len = strlen(str);

	if (str == NULL || *str == '\0')
	return (NULL);

	num_words = count_words(str);
	if (num_words == 0)
	return (NULL);

	matrix = malloc((num_words + 1) * sizeof(char *));
	if (matrix == NULL)
	return (NULL);

	for (i = 0; i <= len; i++)
	{
	if (str[i] == ' ' || str[i] == '\0')
	{
	if (start < i)
	{
	int word_len = i - start;
	char *tmp = malloc((word_len + 1) * sizeof(char));
	if (tmp == NULL)
	{

	for (int j = 0; j < k; j++)

	free(matrix[j]);
	free(matrix);
	return (NULL);
	}
	strncpy(tmp, &str[start], word_len);
	tmp[word_len] = '\0';
	matrix[k] = tmp;
	k++;
	start = i + 1;
	}
	}
	}

	matrix[k] = NULL;
	return (matrix);
}
