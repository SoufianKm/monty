#include "monty.h"

/**
 * execute - executes the opcodes
 * @line: line content
 * @stack: head linked list - stack
 * @count: number of error line
 * @file: poiner to monty file
 *
 * Return: 0 in success, otherwise 1
 */
int execute(char *line, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opcode_fun[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(line, DELIM);
	list_vars.arg = strtok(NULL, DELIM);
	while (opcode_fun[i].opcode && opcode)
	{
		if (strcmp(opcode, opcode_fun[i].opcode) == 0)
		{
			opcode_fun[i].f(stack, count);
			return (0);
		}
		i++;
	}

	if (opcode && opcode_fun[i].opcode == NULL)
	{
		print_err(4, count, opcode);
		close_and_free(file, line, stack);
	}

	return (1);
}

