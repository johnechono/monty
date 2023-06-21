#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "monty.h"

/**
 * push - will push the element into the stack
 * @stack: the given stack
 * @line_count: the ammount of lines
 * Return: null or void
 */
void push(stack_t **stack, unsigned int line_count)
{
	char *a = global.args;

	if ((is_digit(a)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	if (global.struct_data == 1)
	{
		if (!add_node(stack, atoi(global.args)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.args)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
}
