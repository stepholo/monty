#include "monty.h"
/**
* swap - swaps the top two elements of the stack.
* @stack: pointer to the pointer to the top of the element
* @line_number: element line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp; /* a temporary integer to hold stack data*/

	if (ptr == NULL || ptr->next == NULL)
	{
		print_error(line_number, "can't swap, stack too short");
		exit(EXIT_FAILURE);
	}

	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}
