#include "main.h"

/**
 * rotr - rotates the stack to the bottom.
 *
 * @stack: Pointer to the address of the top of the stack.
 * @line_number: Number of the line being executed.
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		stack_t *temp = *stack;

		while (temp->next)
			temp = temp->next;

		temp->prev->next = NULL;

		temp->prev = NULL;
		temp->next = *stack;

		(*stack)->prev = NULL;
		*stack = temp;
	}
	UNUSED(line_number);
}

