#include "monty.h"
/**
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp;/** a temporary integer to hold stack data*/
	if (ptr == NULL || ptr->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}
