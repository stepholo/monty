#include "monty.h"

/**
* rotr - Rotates the stack to the bottom
* @stack: Pointer to the pointer to the top of the stack
* @line_number: Line number of the element
*/
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *last, *second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;

	while (last->next != NULL)
		last = last->next;

	second_last = last->prev;

	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	second_last->next = NULL;
}
