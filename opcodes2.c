#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @stack: pointer to a pointer pointing to head of the stack.
 * @count: error line number.
 */
void _add(stack_t **stack, unsigned int count)
{
	operations(stack, count, '+', "add");
}

/**
 * _nop - Doesn’t do anything.
 * @stack: pointer to a pointer pointing to head of the stack.
 * @count: error line number.
 */
void _nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int count) {}

/**
 * _sub - subtracts the top element of the stack from
 * the second top element of the stack..
 * @stack: pointer to a pointer pointing to head of the stack.
 * @count: error line number.
 */
void _sub(stack_t **stack, unsigned int count)
{
	operations(stack, count, '-', "sub");
}

/**
 * _div - subtracts the top element of the stack from
 * the second top element of the stack..
 * @stack: pointer to a pointer pointing to head of the stack.
 * @count: error line number.
 */
void _div(stack_t **stack, unsigned int count)
{
	operations(stack, count, '/', "div");
}

/**
 * _mul - multiplies the second top element of
 * the stack with the top element of the stack.
 * the second top element of the stack.
 * @stack: pointer to a pointer pointing to head of the stack.
 * @count: error line number.
 */
void _mul(stack_t **stack, unsigned int count)
{
	operations(stack, count, '*', "mul");
}
