#include "monty.h"

/**
* mul - Multiplies the second top element of the stack with the top element
* of the stack
* @stack: pointer to the pointer to the top of the stack
* @line_number: the line number of the elements of the stack
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int mul;
	stack_t *top = *stack;
	stack_t *second = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_error(line_number, "can't mul, stack too short");
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}

	mul = top->n * second->n;

	second->n = mul;
	*stack = second;
	(*stack)->prev = NULL;

	free(top);
}
