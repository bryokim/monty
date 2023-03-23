#include "main.h"

/**
 * exec_loop - execute all instructions in the file.
 *
 * @stack: Pointer to the address of the top of the stack.
 *
 * Return: Function to be executed.
*/
void exec_loop(stack_t **stack)
{
	char opcode[6] = {0}, ch;
	unsigned int line_number = 1;
	void (*func)(stack_t **, unsigned int);

	while (1)
	{
		fscanf(input, "%5s", opcode);
		if (opcode[0] == '\0')
			break;
		if (opcode[0] == '#')
		{
			nop(stack, line_number);
		}
		else
		{
			func = get_opcode_func(opcode);
			if (!func)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				if (stack)
					free_stack(*stack);
				exit(EXIT_FAILURE);
			}
			func(stack, line_number);
		}

		while ((ch = getc(input)) != '\n' && ch != EOF)
			;
		if (ch == EOF)
			break;
		line_number++;
		memset(opcode, 0, 6);
	}
}

