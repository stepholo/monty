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
		printf("L%d: can't pint, stack empty\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ptr->n);
}
