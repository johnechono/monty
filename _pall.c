#include "monty.h"

/**
 * j_pall - will print the stack
 * @line_count: line count
 * @stack: main stack
 * Return: void or nothing
 */
void j_pall(stack_t **stack, unsigned int line_count __attribute__((unused)))
{
	stack_print(*stack);
}
