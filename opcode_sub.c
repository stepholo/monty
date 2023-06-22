#include "monty.h"

/**
* sub - subtract the top elemnt from the second top element
* @stack: pointer to pointer to the top of the stack
* @line_number: Line number of the stack element
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int diff;
	stack_t *top = *stack;
	stack_t *second = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_error(line_number, "can't sub, stack too short");
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}

	diff = second->n - top->n;

	second->n = diff;
	*stack = second;
	(*stack)->prev = NULL;

	free(top);
}

