#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_nodes - Adds multiple nodes to the list.
 * @head: Double pointer to the head of the list.
 */

void add_nodes(listint_t **head)
{
	add_nodeint(head, 0);
	add_nodeint(head, 1);
	add_nodeint(head, 2);
	add_nodeint(head, 3);
	add_nodeint(head, 4);
	add_nodeint(head, 98);
	add_nodeint(head, 402);
	add_nodeint(head, 1024);
}

/**
 * test_list - Prints the list, checks for a loop, and frees the list.
 * @head: Double pointer to the head of the list.
 */

void test_list(listint_t **head)
{
	listint_t *node;

	print_listint_safe(*head);
	node = find_listint_loop(*head);
	if (node != NULL)
	{
	printf("Loop starts at [%p] %d\n", (void *)node, node->n);
	}
	free_listint_safe(head);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
	listint_t *head = NULL;
	listint_t *head2 = NULL;
	listint_t *node;

	add_nodes(&head2);
	test_list(&head2);

	node = add_nodeint(&head, 0);
	add_nodeint(&head, 1);
	add_nodeint(&head, 2);
	add_nodeint(&head, 3);
	add_nodeint(&head, 4);
	add_nodeint(&head, 5);
	add_nodeint(&head, 6);
	node->next = add_nodeint(&head, 7);
	add_nodeint(&head, 98);
	add_nodeint(&head, 402);
	add_nodeint(&head, 1024);
	test_list(&head);

	return (0);
}
