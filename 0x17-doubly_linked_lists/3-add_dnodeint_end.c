#include "lists.h"

/**
 * add_dnodeint_end - Adds new node at end of dlistint_t list.
 * @head: A pointer to head of dlistint_t list.
 * @n: The integer for new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *last;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;

	return (new);
}
