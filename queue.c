#include "monty.h"

/**
 * addqueue - add node to the end of stack
 * @head: head of the stack
 * @n: new value
 */
void addqueue(stack_t **head, int n)
{
	stack_t *h, *new;

	new = *head;
	h = malloc(sizeof(stack_t));
	if (!h)
	{
		printf("Error\n");
		return;
	}

	h->n = n;
	h->next = NULL;
	if (new)
	{
		while (new->next)
			new = new->next;

		new->next = h;
		h->prev = new;
	} else
	{
		*head = h;
		h->prev = NULL;
	}
}
