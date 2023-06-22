#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * j_sub - it substracts the first two nodes in the stack
 * @line_count: the linecount
 * @stack: stack given by main
 * Return: void or nothing
 */
void j_sub(stack_t **stack, unsigned int line_count)
{
	int soln;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	soln = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = soln;
}
