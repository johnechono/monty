#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * node_queue - will add a node to a  stack in queue
 * @n: the number of the node
 * @stack: head of the stack
 * Return: the newly created node, or NULL if
 * memory allocation fails
 */
stack_t *node_queue(stack_t **stack, const int n)
{
	stack_t *fresh = malloc(sizeof(stack_t));
	stack_t *live = *stack;

	if (!fresh)
	{
		free(fresh);
		return (NULL);
	}
	fresh->n = n;

	if (!*stack)
	{
		fresh->next = NULL;
		fresh->prev = NULL;
		*stack = fresh;
		return (fresh);
	}

	while (live)
	{
		if (!live->next)
		{
			fresh->next = NULL;
			fresh->prev = live;
			live->next = fresh;
			break;
		}
		live = live->next;
	}

	return (fresh);
}
/**
 * node_add - will add a node to the start of the stack
 * @n: the number for the fresh node
 * @stack: head of the stack
 * Return: the new node or NULL
 */
stack_t *node_add(stack_t **stack, const int n)
{
	stack_t *fresh = malloc(sizeof(stack_t));

	if (!fresh)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(fresh);
		return (NULL);
	}
	fresh->n = n;

	fresh->next = *stack;
	fresh->prev = NULL;
	if (*stack)
		(*stack)->prev = fresh;

	*stack = fresh;
	return (fresh);
}
/**
 * stack_print - will print the contents of the stack
 * @stack: head of the stack
 * Return: elements in the list
 */
size_t stack_print(const stack_t *stack)
{
	size_t a = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		a++;
	}
	return (a);
}
/**
 * stack_free - will freesthea dlistint_t linked list
 * @stack: head of the list
 * Return: void or nothing
 */
void stack_free(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
