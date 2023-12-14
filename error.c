#include "monty.h"

/**
 * print_err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * @line_nbr: error line number
 * @name: is filename or instruction function
 */
void print_err(int error_code, int line_nbr, char *name)
{
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", name);
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nbr, name);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}
