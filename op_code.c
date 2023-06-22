#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * j_opcode - the function in charge of executing builtins
 * @line_count: line count
 * @stack: the main stack
 * @str: the string to be compared
 * Return: nothing ot null
 */
void j_opcode(stack_t **stack, char *str, unsigned int line_count)
{
	int j = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.struct_data = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.struct_data = 0;
		return;
	}

	while (op[j].opcode)
	{
		if (strcmp(op[j].opcode, str) == 0)
		{
			op[j].f(stack, line_count);
			return;
		}
		j++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, str);
	status = EXIT_FAILURE;
}
