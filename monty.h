#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct instruction_s - the opcode and function
 * @n: the function that will  handle the opcode
 * @opcode: opcode
 * Description: the opcode and its functions
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*n)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define INSTRUCTIONS { \
		{"push", push},\
		{"pall", pall},\
		{"sub", _sub},\
		{"mod", mod},\
		{"pchar", pchar},\
		{"pstr", pstr},\
		{"rotl", rotl},\
		{"rotr", rotr},\
		{"pint", pint},\
		{"pop", pop},\
		{"swap", swap},\
		{"nop", nop},\
		{"div", _div},\
		{"mul", _mul},\
		{"add", _add},\
		}

/**
 * struct stack_s - the doubly linked list representation of a queue
 * @prev: pointer to the previous element of the queue
 * @next: pointer to the next element of the queue
 * @j: integer value
 * Description: a doubly linked list node structure for stack,
 * queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int j;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct help - the argument for the present opcode
* @struct_data: the stack mode and queue
* @args: the string argument
* Description: the global struct used to easily pass data
* around the functions
*/
typedef struct help
{
	int struct_data;
	char *args;
} help;
help global;

extern int status;

void _add(stack_t **stack, unsigned int line_count);
void _sub(stack_t **stack, unsigned int line_count);
void _mul(stack_t **stack, unsigned int line_count);
void mod(stack_t **stack, unsigned int line_count);
void pchar(stack_t **stack, unsigned int line_count);
void pstr(stack_t **stack, unsigned int line_count);
void rotl(stack_t **stack, unsigned int line_count);
void rotr(stack_t **stack, unsigned int line_count);
void opcode(stack_t **stack, char *str, unsigned int line_count);
void push(stack_t **stack, unsigned int line_count);
void pall(stack_t **stack, unsigned int line_count);
void pint(stack_t **stack, unsigned int line_count);
void swap(stack_t **stack, unsigned int line_count);
void pop(stack_t **stack, unsigned int line_count);
void nop(stack_t **stack, unsigned int line_count);
void _div(stack_t **stack, unsigned int line_count);

void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);
stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);

int isnumber(char *str);
int is_digit(char *string);

#endif

