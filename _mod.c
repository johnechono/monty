#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * j_mod - will compute the remainder of the division
 * @stack: given by the main
 * @line_count: the line counter
 * Return: void or nothing
 */
void j_mod(stack_t **stack, unsigned int line_count)
{
	int soln;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	soln = ((*stack)->next->n) % ((*stack)->n);
	j_pop(stack, line_count);
	(*stack)->n = soln;
}
