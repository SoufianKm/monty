#include "monty.h"

/**
 * _push - add node to the stack
 * @head: doubly linked list of head stack
 * @count: error line number
 */
void _push(stack_t **head, unsigned int count)
{
	int nbr, i = 0, flag = 0;

	if (list_vars.arg)
	{
		if (list_vars.arg[0] == '-')
			i++;

		for (; list_vars.arg[i] != '\0'; i++)
			if (list_vars.arg[i] > 57 || list_vars.arg[i] < 48)
				flag = 1;
	}

	if (!list_vars.arg || flag == 1)
	{
		print_err(3, count, NULL);
		close_and_free(list_vars.file, list_vars.line, head);
	}

	nbr = atoi(list_vars.arg);
	if (list_vars.mode == 0)
		add_to_stack(head, nbr);
	else
		add_to_queue(head, nbr);
}

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
	if (!h)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _pint - prints the value at the top of the stack.
 * @stack: pointer to a pointer pointing to head of the stack.
 * @count: error line number.
 */
void _pint(stack_t **stack, unsigned int count)
{
	if (!stack || !*stack)
		print_err(5, count, NULL);
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack.
 * @stack: pointer to a pointer pointing to head of the stack.
 * @count: error line number.
 */
void _pop(stack_t **stack, unsigned int count)
{
	stack_t *tmp;

	if (!stack || !*stack)
		print_err(6, count, NULL);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);
}
