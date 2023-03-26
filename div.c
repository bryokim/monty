#include "monty.h"


/**
 * _div - divide the second top element with the top most element.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!(*stack && (*stack)->next))
	{
		char *error_msg = ": can't div, stack too short\n";

		fprintf(stderr, "%s%u%s", "L", line_number, error_msg);
		if (*stack)
			free(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "%s%u%s", "L", line_number, ": division by zero\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

