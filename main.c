#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
 * usage_error - will print usage message and exit
 * Return: 0
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * error_file -will print file error message and exit
 * @argv: argument vector
 * Return: nothing
 */
void error_file(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

int status = 0;
/**
 * main - the entry point
 * @argc: number of arguments
 * @argv: the argument list passed
 * Return: nothing or null
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t len_buf = 0;
	stack_t *stack = NULL;
	unsigned int line_count = 1;
	char *buffer = NULL;
	char *str = NULL;

	global.struct_data = 1;
	if (argc != 2)
		usage_error();
	file = fopen(argv[1], "r");

	if (!file)
		error_file(argv[1]);
	while (getline(&buffer, &len_buf, file) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_count++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_count++;
			continue;
		}
		global.args = strtok(NULL, " \t\n");
		opcode(&stack, str, line_count);
		line_count++;
	}
	free(buffer);
	stack_free(stack);
	fclose(file);
	exit(status);
}
