#include "monty.h"
/**
* mod - opcode modulus
* @stack: stack  pointer
* @line_number: line number
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int mod;
	stack_t *top = *stack;
	stack_t *second = (*stack)->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		print_error(line_number, "can't mod, stack too short");
		exit(EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		print_error(line_number, "division by zero");
		exit(EXIT_FAILURE);
	}

	mod = second->n % top->n;

	second->n = mod;
	*stack = second;
	(*stack)->prev = NULL;

	free(top);
}
