#include "monty.h"

list_vars_t list_vars = { NULL, NULL, NULL, 0};

/**
 * main - Entry point
 * @ac: size of arguments
 * @av: pointer to array of arguments
 *
 * Return: 0 always on success
 */
int main(int ac, char **av)
{
	FILE *file;
	stack_t *stack = NULL;
	unsigned int count = 0;
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;

	if (ac != 2)
		print_err(1, 0, NULL);

	file = fopen(av[1], "r");
	list_vars.file = file;
	if (!file)
		print_err(2, 0, av[1]);

	while (linelen > 0)
	{
		line = NULL;
		linelen = getline(&line, &linecap, file);
		list_vars.line = line;
		count++;
		if (linelen > 0)
			execute(line, &stack, count, file);

		free(line);
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
