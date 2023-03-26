#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		stack_t *temp = *stack, *new_top = (*stack)->next;

		while (temp->next)
			temp = temp->next;

		temp->next = *stack;
		(*stack)->next = NULL;
		(*stack)->prev = temp;

		new_top->prev = NULL;
		*stack = new_top;
	}
	UNUSED(line_number);
}

