#include "monty.h"

/**
* j_rotl - will rotate the first element in the stack
* @stack: head of the stack
* @line_count: the line count
* Return: void or nothing
*/
void j_rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *lefty;
	stack_t *righty;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	lefty = righty = *stack;

	while (righty->next)
	{
		righty = righty->next;
	}

	righty->next = lefty;
	lefty->prev = righty;
	*stack = lefty->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
