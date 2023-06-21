#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pint - will print the data at the top
 * @stack: given stack
 * @line_count: line amount
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_count)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}
