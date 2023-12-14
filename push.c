#include "monty.h"

/**
 * _push - add node to the stack
 * @head: doubly linked list of head stack
 * @count: error line number
 */
void _push(stack_t **head, unsigned int count)
{
	int nbr, i = 0, flag = 0;

	if (list_vars.arg)
	{
		if (list_vars.arg[0] == '-')
			i++;

		for (; list_vars.arg[i] != '\0'; i++)
			if (list_vars.arg[i] > 57 || list_vars.arg[i] < 48)
				flag = 1;
	}

	if (!list_vars.arg || flag == 1)
	{
		print_err(3, count, NULL);
		close_and_free(list_vars.file, list_vars.line, head);
	}

	nbr = atoi(list_vars.arg);
	if (list_vars.mode == 0)
		add_to_stack(head, nbr);
	else
		add_to_queue(head, nbr);
}
