#include "monty.h"

/**
 * pall - print all items in the stack.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
	UNUSED(line_number);
}

