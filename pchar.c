#include "monty.h"


/**
 * pchar - print character value of top element.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "%s%u%s", "L", line_number, "can't pchar, stack empty\n");
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		char *error_msg = "can't pchar, value out of range\n";

		fprintf(stderr, "%s%u%s", "L", line_number, error_msg);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

