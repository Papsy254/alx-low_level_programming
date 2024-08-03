#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the head of the list
 * @str: string to be duplicated and added to the list
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new; 
	list_t *temp = *head;

	new = malloc(sizeof(list_t));
	if (new == NULL)
	return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
	free(new);
	return (NULL);
	}

	new->len = strlen(str);
	new->next = NULL;

	if (*head == NULL)
	{
	*head = new;
	}
	else
	{
	while (temp->next != NULL)
	temp = temp->next;
	temp->next = new;
	}
	return (new);
}
