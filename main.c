#include "main.h"

FILE *input = NULL;

/**
 * main - entry point.
 *
 * @argc: Number of arguments.
 * @argv: Array  of arguments.
 *
 * Return: Always 0.
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "%s", "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	input = fopen(argv[1], "r");
	if (!input)
	{
		fprintf(stderr, "%s%s\n", "Error: Can't open file ", argv[1]);
		exit(EXIT_FAILURE);
	}
	exec_loop(&stack);

	if (stack)
		free_stack(stack);
	printf("Exited normally\n");

	return (0);
}

