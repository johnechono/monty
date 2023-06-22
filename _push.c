#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * j_push - will push an element into the stack
 * @line_count: line count
 * @stack: the stack the main gives
 * Return: void or nothing
 */
void j_push(stack_t **stack, unsigned int line_count)
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
		if (!node_add(stack, atoi(global.args)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	else
	{
		if (!node_queue(stack, atoi(global.args)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
}
