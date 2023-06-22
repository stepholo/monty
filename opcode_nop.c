#include "monty.h"
/**
* nop - does nothing
* @stack: pointer to the top of the stack
* @line_number: element line number
*/
void nop(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	/**
	 * the opcode NOP is an equivalent to NULL in c
	 * therefore print nothing
	 */
	;
}
