#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * j_mul - divides the next top value by the top value
 * @line_count: the line counter
 * @stack: main stack
 * Return: void or nothing
 */
void j_mul(stack_t **stack, unsigned int line_count)
{
	int soln;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	soln = ((*stack)->next->n) * ((*stack)->n);
	j_pop(stack, line_count);
	(*stack)->n = soln;
}

