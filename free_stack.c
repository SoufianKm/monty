#include "monty.h"

/**
 * free_stack - free memory allocated for a doubly linked list given
 * @head: pointer to a head of stack
 */
void free_stack(stack_t *head)
{
	stack_t *aux;

	if (!head)
		return;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
	free(head), head = NULL;
}
