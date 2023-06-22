#include "monty.h"

/**
* j_rotr - will rotate the last node of a stack
* @line_count: the line count
* @stack: head of the stack
* Return: void or nothing
*/
void j_rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *prev;
	stack_t *under;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	under = *stack;

	while (under->next)
	{
		under = under->next;
	}

	prev = under->prev;
	under->next = *stack;
	under->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = under;
	*stack = under;
}
