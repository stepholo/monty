#ifndef MONTY_H
#define MONTY_H

/* Standard Library Header Files */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Structures */
/**
* struct stack_s - double linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next elemnt of the stack (or queue)
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
* struct intruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queue, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global variable */
extern stack_t *stack;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number);
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number);
void _stack(stack_t **stack, __attribute((unused))unsigned int line_number);
void _queue(stack_t **stack, __attribute((unused))unsigned int line_number);

/* Helper functions */
void print_error(unsigned int line_number, const char *message);
int is_integer(const char *str);
int process_instructions(FILE *file, stack_t **stack);
void cleanup(stack_t *stack);

#endif /* MONTY_H */
