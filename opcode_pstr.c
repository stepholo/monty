#include "monty.h"
#include <ctype.h>

/**
* pstr - Prints the string starting at the top of the stack,
* followed by new line
* @stack: Pointer to the pointer to the top of the stack
* @line_number: line number of the element on the stack
*/
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}

/**
 * pchar - prints the character at the top of a stack
 * @stack: stack pointer
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int val;
	if ((*stack) == NULL)
	{
		print_error(line_number, "can't pchar, stack empty");
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	val = ptr->n;
	if (!isprint(val))
	{
		print_error(line_number, "can't pchar, value out of range");
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	putchar(val);
	putchar('\n');
}
