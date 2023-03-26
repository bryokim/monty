#include "monty.h"

/**
 * add  - add top most  element to the second top element.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!(*stack && (*stack)->next))
	{
		char *error_msg = ": can't add, stack too short\n";

		fprintf(stderr, "%s%u%s", "L", line_number, error_msg);
		if (*stack)
			free(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

