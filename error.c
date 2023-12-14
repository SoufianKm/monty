#include "monty.h"

/**
 * print_err - Prints appropiate error messages determined
 * by their error code.
 * @error_code: The error codes are the following:
 *  (1) => Missed file or more than one file to the program.
 *  (2) => The file provided is not a file that can be opened or read.
 *  (3) => The file provided contains an invalid instruction.
 *  (4) => If argument is not an integer or if there is no
 *  argument given to "push"
 *  (5) => If the stack is empty for "pint".
 *  (6) => If the stack is empty for "pop".
 *  (7) => If the stack contains less than two elements for "swap".
 * @line_nbr: error line number
 * @name: is filename or instruction function
 */
void print_err(int error_code, int line_nbr, char *name)
{
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", name);
			exit(EXIT_FAILURE);
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nbr, name);
			break;
		case 4:
			fprintf(stderr, "L%d: usage: push integer\n", line_nbr);
			exit(EXIT_FAILURE);
			break;
		case 5:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_nbr);
			exit(EXIT_FAILURE);
			break;
		case 6:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_nbr);
			exit(EXIT_FAILURE);
			break;
		case 7:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_nbr);
			exit(EXIT_FAILURE);
			break;
		default:
			break;
	}
}

/**
 * close_and_free - close an open file and freeing memory
 * @file: file opened
 * @line: line content
 * @stack: doubly linked list representation of a stack (or queue)
 */
void close_and_free(FILE *file, char *line, stack_t **stack)
{
	fclose(file);
	free(line), line = NULL;
	free_stack(*stack), *stack = NULL;
	exit(EXIT_FAILURE);
}
