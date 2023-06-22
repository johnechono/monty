#include "monty.h"

/**
* rotr - will rotate the last node of a stack
* @line_count: the line count
* @stack: head of the stack
* Return: void or nothing
*/
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *previous;
	stack_t *under;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	under = *stack;

	while (under->next)
	{
		under = under->next;
	}

	previous = under->previous;
	under->next = *stack;
	under->previous = NULL;
	previous->next = NULL;
	(*stack)->previous = under;
	*stack = under;
}
