#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: doubly linked list of head stack
 * @count: error line number
 */
void _mod(stack_t **stack, unsigned int count)
{
	operations(stack, count, '%', "mod");
}
