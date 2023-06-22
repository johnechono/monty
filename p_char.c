#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * j_pchar - will print the int at the top of the stack
 * @line_count: line count
 * @stack: main stack
 * Return: void or nothing
 */
void j_pchar(stack_t **stack, unsigned int line_count)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*stack)->n);
}
