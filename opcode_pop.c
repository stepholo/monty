#include "monty.h"

/**
* pop - Removes the top element of the stack
* @stack: Pointer to the pointer to the top of the stack
* @line_number: The line number of the element
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		print_error(line_number, "can't pop an empty stack");

	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
