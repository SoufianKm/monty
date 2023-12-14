#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new value
 *
 * Return: no return
*/
void addnode(stack_t **head, int n)
{
	stack_t *h = NULL, *new = NULL;

	new = *head;
	h = malloc(sizeof(stack_t));
	if (!h)
	{
		free_stack(h);
		printf("Error\n");
		exit(0);
	}

	if (new)
		new->prev = h;

	h->n = n;
	h->prev = NULL;
	h->next = *head;
	*head = h;
}
