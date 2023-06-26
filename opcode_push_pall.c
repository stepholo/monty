#include "monty.h"

/**
* print_error - prints the error messages to stderr
* @line_number: Error message line lnumber
* @message: the error message
*/
void print_error(unsigned int line_number, const char *message)
{
	fprintf(stderr, "L%u: %s\n", line_number, message);
}

/**
* is_integer - Checks whether user input is an integer
* @str: Pointer to the the user input
* Return: 1 for and integer else 0
*/
int is_integer(const char *str)
{
	int i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
* push - Adds element to the stack
* @stack: Pointer to the pointer of the end of the stack
* @line_number: Line number of the stack
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n");
	stack_t *new_node;

	if (!arg || !is_integer(arg))
	{
		print_error(line_number, "usage: push integer");
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		print_error(line_number, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;

}

/**
* pall - prints all the values on the stack, starting from the
* top of the stack
* @stack: Pointer to the pointer to the top of the stack
* @line_number: line number of the stack`
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		fflush(stdout);
		current = current->next;
	}
}
