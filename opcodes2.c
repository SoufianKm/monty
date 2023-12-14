#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @stack: pointer to a pointer pointing to head of the stack.
 * @count: error line number.
 */
void _add(stack_t **stack, unsigned int count)
{
	int sum;

	if (!stack || !*stack || (*stack)->next == NULL)
		print_err(7, count, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _nop - Doesn’t do anything.
 * @stack: pointer to a pointer pointing to head of the stack.
 * @count: error line number.
 */
void _nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int count) {}
