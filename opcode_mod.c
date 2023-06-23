#include "monty.h"
/**
 * mod - opcode modulus
 * @stack: stack  pointer
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero",line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
