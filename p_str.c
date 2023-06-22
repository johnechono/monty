#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * j_pstr - it will print the contents of a stack_t as a string
 * @stack: main stack
 * @line_count: line count
 * Return: nothing or null
 */
void j_pstr(stack_t **stack, unsigned int line_count __attribute__((unused)))
{
	stack_t *live = *stack;

	while (live)
	{
		if (live->n <= 0 || live->n > 127)
		{
			break;
		}
		putchar((char) live->n);
		live = live->next;
	}
	putchar('\n');
}
