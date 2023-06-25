#include "monty.h"
/**
* _div - performing the div opcode
* @stack: stack pointer
* @line_number: line number
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int div;
	stack_t *top = *stack;
	stack_t *second = (*stack)->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		print_error(line_number, "can't div, stack too short");
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		print_error(line_number, "division by zero");
		exit(EXIT_FAILURE);
	}

	div = second->n / top->n;

	second->n = div;
	*stack = second;
	(*stack)->prev = NULL;

	free(top);
}
