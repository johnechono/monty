#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define INSTRUCTIONS { \
		{"add", j_add},\
		{"sub", j_sub},\
		{"mod", j_mod},\
		{"pchar", j_pchar},\
		{"pstr", j_pstr},\
		{"rotl", j_rotl},\
		{"rotr", j_rotr},\
		{"push", j_push},\
		{"pall", j_pall},\
		{"pint", j_pint},\
		{"pop", j_pop},\
		{"swap", j_swap},\
		{"nop", j_nop},\
		{"div", j_div},\
		{"mul", j_mul},\
		{NULL, NULL} \
	}
/**
* struct help -  argument for the current opcode
* @struct_data:  stack mode and queue
* @args:  the string argument
* Description: the global structure that is used to easily pass data
* around the functions
*/
typedef struct help
{
	int struct_data;
	char *args;
} help;
help global;

extern int status;

int is_digit(char *string);
int is_number(char *str);

void j_div(stack_t **stack, unsigned int line_count);
void j_add(stack_t **stack, unsigned int line_count);
void j_sub(stack_t **stack, unsigned int line_count);
void j_mul(stack_t **stack, unsigned int line_count);
void j_mod(stack_t **stack, unsigned int line_count);
void j_pchar(stack_t **stack, unsigned int line_count);
void j_pstr(stack_t **stack, unsigned int line_count);
void j_rotl(stack_t **stack, unsigned int line_count);
void j_rotr(stack_t **stack, unsigned int line_count);
void j_push(stack_t **stack, unsigned int line_count);
void j_pall(stack_t **stack, unsigned int line_count);
void j_pint(stack_t **stack, unsigned int line_count);
void j_swap(stack_t **stack, unsigned int line_count);
void j_pop(stack_t **stack, unsigned int line_count);
void j_nop(stack_t **stack, unsigned int line_count);
void j_opcode(stack_t **stack, char *str, unsigned int line_count);

void stack_free(stack_t *stack);
size_t stack_print(const stack_t *stack);
stack_t *node_add(stack_t **stack, const int n);
stack_t *node_queue(stack_t **stack, const int n);

#endif
