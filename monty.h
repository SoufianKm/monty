#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DELIM " \t\n"

/**
 * struct bus_s - variables -args, file, line line
 * @arg: value
 * @file: pointer to monty file
 * @line: line content
 * @lifi: flag change stack <-> queue
 *
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *line;
	int lifi;
} bus_t;

extern bus_t bus;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int execute(char *, stack_t **, unsigned int, FILE *);
void free_stack(stack_t *);
ssize_t getline(char **, size_t *, FILE *);
void _push(stack_t **, unsigned int);
void addnode(stack_t **, int);
void addqueue(stack_t **, int);
void _pall(stack_t **, unsigned int);

#endif
