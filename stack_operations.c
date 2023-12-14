#include "monty.h"

/**
 * add_to_stack - add node to the head stack
 * @head: head of the stack
 * @n: new value
*/
void add_to_stack(stack_t **head, int n)
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

/**
 * add_to_queue - add node to the end of stack
 * @head: head of the stack
 * @n: new value
 */
void add_to_queue(stack_t **head, int n)
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

void operations(stack_t **stack, unsigned int count,
		char operator, char *opname)
{
	int sum;

	if (!stack || !*stack || (*stack)->next == NULL)
		print_err(7, count, opname);

	if (operator == '/' || operator == '%')
		if ((*stack)->n == 0)
			print_err(8, count, NULL);

	(*stack) = (*stack)->next;
	switch (operator)
	{
		case '+':
			sum = (*stack)->n + (*stack)->prev->n;
			break;
		case '-':
			sum = (*stack)->n - (*stack)->prev->n;
			break;
		case '/':
			sum = (*stack)->n / (*stack)->prev->n;
			break;
		case '*':
			sum = (*stack)->n * (*stack)->prev->n;
			break;
		case '%':
			sum = (*stack)->n % (*stack)->prev->n;
			break;
		default:
			break;
	}

	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
