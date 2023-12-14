#include "monty.h"

/**
 * _push - add node to the stack
 * @head: stack head
 * @count: error line number
 *
 * Return: no return
 */
void _push(stack_t **head, unsigned int count)
{
	int nbr, i = 0, flag = 0;

	if (list_vars.arg)
	{
		if (list_vars.arg[0] == '-')
			i++;

		for (; list_vars.arg[i] != '\0'; i++)
		{
			if (list_vars.arg[i] > 57 || list_vars.arg[i] < 48)
				flag = 1;
		}
	}

	if (!list_vars.arg || flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(list_vars.file);
		free(list_vars.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	nbr = atoi(list_vars.arg);
	if (list_vars.mode == 0)
		addnode(head, nbr);
	else
		addqueue(head, nbr);
}
