#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
* pop - will pop the  top
* @stack: given stack
* @line_count: error messages line number
* Return: void
*/
void pop(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
