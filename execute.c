#include "monty.h"

/**
 * execute - executes the opcodes
 * @line: line content
 * @stack: head linked list - stack
 * @count: number of error line
 * @file: poiner to monty file
 *
 * Return: no return
 */
int execute(char *line, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {{"push", _push}, {"pall", _pall},{NULL, NULL}};
	unsigned int i = 0;
	char *op;

	op = strtok(line, DELIM);
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, DELIM);
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(line), line = NULL;
		free_stack(*stack), *stack = NULL;
		exit(EXIT_FAILURE);
	}
	return (1);
}

