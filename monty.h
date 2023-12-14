#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>

#define DELIM " \t\n"

/**
 * struct list_vars - linked list represtation of a variables to share
 * @arg: value
 * @file: pointer to monty file
 * @line: line content
 * @mode: flag change stack <-> queue
 *
 * Description: share variables through the program
 */
typedef struct list_vars
{
	char *arg;
	FILE *file;
	char *line;
	int mode;
} list_vars_t;

/* GLOBAL OPCODE TOKENS */
extern list_vars_t list_vars;

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
ssize_t getline(char **, size_t *, FILE *);

/* Stacks operations */
void add_to_stack(stack_t **, int);
void add_to_queue(stack_t **, int);

/* Free Memory */
void free_stack(stack_t *);

/* Opcodes Operations */
void _push(stack_t **, unsigned int);
void _pall(stack_t **, unsigned int);

/* Handl Errors */
void print_err(int, int, char *);
void close_and_free(FILE *, char *, stack_t **);

#endif
