#include "main.h"

/**
 * mod - find the modulus of second top element to the top element.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!(*stack && (*stack)->next))
	{
		fprintf(stderr, "%s%u%s", "L", line_number, ": can't mod\n");
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

	result = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

