#include "monty.h"

/**
 * sub - subtract top element from the second top element.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!(*stack && (*stack)->next))
	{
		char *error_msg = ": can't sub, stack too short\n";

		fprintf(stderr, "%s%u%s", "L", line_number, error_msg);
		if (*stack)
			free(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

