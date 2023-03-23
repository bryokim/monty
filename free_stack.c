#include "main.h"

/**
 * free_stack - free stack.
 *
 * @stack: Pointer to the address of the top of the stack.
*/
void free_stack(stack_t *stack)
{
	stack_t *temp = stack;
	int i = 0;

	while (stack)
	{
		stack = stack->next;
		free(temp);
		temp = stack;
		i++;
	}
	printf("Freed %d\n", i);
}

