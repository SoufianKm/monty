#include "monty.h"

/**
 * free_stack - free memory allocated for a doubly linked list given
 * @head: pointer to a head of stack
 */
void free_stack(stack_t *head)
{
	stack_t *h;

	if (!head)
		return;

	h = head;
	while (head)
	{
		h = head->next;
		free(head);
		head = h;
	}
	free(head), head = NULL;
}
