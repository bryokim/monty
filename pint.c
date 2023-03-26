#include "monty.h"

/**
 * pint - print integer value of the top element.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "%s%u%s", "L", line_number, ": can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

