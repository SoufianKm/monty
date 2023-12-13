#include "monty.h"

/**
 * _pall - print the stack elements
 * @head: stack head
 * @count: error line number
 *
 * Return: no return
*/
void _pall(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *h;

	h = *head;
	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
