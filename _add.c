#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * j_add - will add the first two nodes of the stack
 * @stack: this is the stack given by main
 * @line_count: linecount
 * Return: void
 */
void j_add(stack_t **stack, unsigned int line_cnt)
{
	int soln;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		status = EXIT_FAILURE;
		return;
	}

	soln = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = soln;
}
