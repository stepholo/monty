#include "monty.h"
/**
* pint - prints the value at the top of the stack
* @stack: stack pointer
* @line_number: line number
*
* Return: value of the top element or 1
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		print_error(line_number, "can't pint, stack empty");
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ptr->n);
}
