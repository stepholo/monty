#include "monty.h"

/**
* add - adds the top two elements of the stack
* @stack: pointer to pointer of the top of the stack
* @line_number: Line number of the stack
*/
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *top = *stack;
	stack_t *second = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
		print_error(line_number, "can't add, stack too short");

	sum = top->n + second->n;

	second->n = sum;
	*stack = second;
	(*stack)->prev = NULL;

	free(top);
}
