#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap -  will swaps data from the top to previous
 * @line_count: line count
 * @stack: main stack
 * Return: void or nothing
 */
void swap(stack_t **stack, unsigned int line_count)
{
	stack_t *temp = NULL;
	int temp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	temp = *stack;
	temp_n = temp->n;
	temp->n = temp_n;

	temp->n = temp->next->n;
	temp->next->n = temp_n;

}
