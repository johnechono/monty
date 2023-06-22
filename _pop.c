#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"
/**
* j_pop - will pop the top
* @line_count: line count
* @stack: main stack
* Return: void or nothing
*/
void j_pop(stack_t **stack, unsigned int line_count)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
