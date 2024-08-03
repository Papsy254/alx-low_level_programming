#include <stdlib.h>
#include <stdio.h>

int word_count(char *str);
int word_len(char *str);

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings (words),
 *         or NULL if str == NULL or str == "" or on failure.
 */
char **strtow(char *str)
{
    char **words;
    int i, j, k, count, len;

    if (str == NULL || *str == '\0')
        return (NULL);

    count = word_count(str);
    if (count == 0)
        return (NULL);

    words = malloc((count + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);

    for (i = 0, j = 0; i < count; i++)
    {
        while (str[j] == ' ')
            j++;

        len = word_len(str + j);
        words[i] = malloc((len + 1) * sizeof(char));
        if (words[i] == NULL)
        {
            for (k = 0; k < i; k++)
                free(words[k]);
            free(words);
            return (NULL);
        }

        for (k = 0; k < len; k++)
            words[i][k] = str[j++];
        words[i][k] = '\0';
    }
    words[i] = NULL;

    return (words);
}

/**
 * word_count - Counts the number of words in a string.
 * @str: The string to count words in.
 *
 * Return: The number of words in the string.
 */
int word_count(char *str)
{
    int count = 0, in_word = 0;

    while (*str)
    {
        if (*str == ' ')
            in_word = 0;
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        str++;
    }

    return (count);
}

/**
 * word_len - Calculates the length of a word.
 * @str: The string to calculate the word length in.
 *
 * Return: The length of the word.
 */
int word_len(char *str)
{
    int len = 0;

    while (str[len] && str[len] != ' ')
        len++;

    return (len);
}
