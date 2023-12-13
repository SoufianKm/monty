#include "monty.h"

/**
 * f_queue - prints the top
 * @head: stack head
 * @count: line_number
 */
void _queue(stack_t **head __attribute__((unused)), unsigned int count)
{
	(void) count;

	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new value
 * @head: head of the stack
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		return;
	}

	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;

		aux->next = new_node;
		new_node->prev = aux;
	} else
	{
		*head = new_node;
		new_node->prev = NULL;
	}
}
