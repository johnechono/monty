#include "monty.h"

/**
 * pall - will print the stack
 * @stack: the given stack
 * @line_count: the number of lines
 * Return: void or null
 */
void pall(stack_t **stack, unsigned int line_count __attribute__((unused)))
{
	print_stack(*stack);
}
