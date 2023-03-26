#include "monty.h"

/**
 * swap - swap top element with second top element.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int data;

	if (!(*stack && (*stack)->next))
	{
		char *error = ": can't swap, stack too short\n";

		fprintf(stderr, "%s%u%s", "L", line_number, error);
		if (*stack)
			free(*stack);
		exit(EXIT_FAILURE);
	}
	data = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = data;
}

