#include "monty.h"

/**
 * pall - will print the stack
 * @line_count: line count
 * @stack: main stack
 * Return: void or nothing
 */
void pall(stack_t **stack, unsigned int line_count __attribute__((unused)))
{
	stack_print(*stack);
}
