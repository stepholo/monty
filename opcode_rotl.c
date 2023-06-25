#include "monty.h"

/**
* rotl - rotates the stack to the top
* @stack: pointer to the pointer of the top of the stack
* @line_number: line number of a stack element
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = (*stack)->next;
	stack_t *last = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	*stack = second;
	second->prev = NULL;
	last->next = top;
	top->prev = last;
	top->next = NULL;
}
