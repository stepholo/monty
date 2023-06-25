#include "monty.h"


/**
* cleanup - Free the memory allocated to the nodes
* @stack: pointer to the top of the stack
*/
void cleanup(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next = NULL;

	while (current != NULL)
	{
		current = current->next;
		free(current);
		current = next;
	}
}
/**
* main - Programs Entry point
* @argv: Argument vector
* @argc: Argurment count
* Return: with exit failure of failure or exit success on success
*/
int main(int argc, char *argv[])
{
	FILE *file;

	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	process_instructions(file, &stack);

	fclose(file);

	cleanup(stack);

	return (0);
}

/**
* execute_instruction - Executes a single instruction
* @instruction: The opcode and corresponding function to execute
* @stack: Pointer to the top of the stack
* @line_number: The current line number
* @opcode: The opcode to execute
* Return: 1 if the instruction was executed succesfully, 0 otherwise
*/
int execute_instruction(instruction_t *instruction, stack_t **stack,
		unsigned int line_number, char *opcode)
{
	if (instruction->opcode ==  NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (0);
	}

	instruction->f(stack, line_number);
	return (1);
}

/**
* process_instructions - Read the bytecode file and
* process instructions contained in the file
* @file: File containing intructions
* @stack: Pointer to the top of the stack
* Return: The exit status
*/
int process_instructions(FILE *file, stack_t **stack)
{
	char line[1024];
	unsigned int line_number = 1;
	int i;
	char *opcode;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (line[0] == '#')
		{
			line_number++;
			continue;
		}
		opcode = strtok(line, " \t\n");
		if (opcode)
		{
			instruction_t instructions[] = {
				{"push", push}, {"pall", pall}, {"pop", pop}, {"add", add},
				{"pint", pint}, {"swap", swap}, {"nop", nop}, {"sub", sub},
				{"mul", mul}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
				{"stack", _stack}, {"queue", _queue}, {"mod", mod}, {"div", _div},
				{"pchar", pchar},
				/* Add more opcode-function paires as needed */
				{NULL, NULL}
			};

			for (i = 0; instructions[i].opcode != NULL; i++)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					if (!execute_instruction(&instructions[i], stack, line_number, opcode))
						return (EXIT_FAILURE);
					break;
				}
			}
		}
		line_number++;
	}
	return (EXIT_SUCCESS);
}
