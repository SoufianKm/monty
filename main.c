#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};
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
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (linelen > 0)
	{
		line = NULL;
		linelen = getline(&line, &linecap, file);
		bus.line = line;
		count++;
		if (linelen > 0)
			execute(line, &stack, count, file);

		free(line);
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
