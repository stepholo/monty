#include "monty.h"

/**
* _stack - changes the mode to stack
* @stack: Pointer to the pointer to the top of the stack
* @line_number: line number of the element
*/
void _stack(stack_t **stack, __attribute((unused))unsigned int line_number)
{
	(void)stack;
}

/**
* _queue - changes mode to queue
* @stack: pointer to the pointer to the top of top of the queue
* @line_number: line number of the element
*/
void _queue(stack_t **stack, __attribute((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	current->prev->next = NULL;
	current->prev = NULL;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->prev = current;
	*stack = current->prev;
	current->prev = NULL;
}
