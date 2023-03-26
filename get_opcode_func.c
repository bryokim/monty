#include "monty.h"

/**
 * get_opcode_func - get function to run.
 *
 * @opcode: opcode to match the function to.
 *
 * Return: function to execute.
*/
void (*get_opcode_func(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", &push},
		{"pop", &pop},
		{"pall", &pall},
		{"pint", &pint},
		{"swap", &swap},
		{"add", &add},
		{"sub", &sub},
		{"mul", &mul},
		{"div", &_div},
		{"mod", &mod},
		{"pchar", &pchar},
		{"pstr", &pstr},
		{"rotl", &rotl},
		{"rotr", &rotr},
		{"\0", NULL},
	};
	while (instructions[i].f != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return  (instructions[i].f);
		i++;
	}
	return (NULL);
}

