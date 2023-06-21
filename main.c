#include <string.h>
#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * error_usage - will print the usage message and exit
 * Return: null
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * file_error - will print the file error message and exit
 * @argv: argument vector
 * Return: nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

int status = 0;
/**
 * main - point of entry
 * @argv: argument list passed
 * @argc: argumrnt amount
 * Return: null
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_count = 1;

	global.struct_data = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while (getline(&buffer, &buf_len, file) != -1)
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
	free_stack(stack);
	fclose(file);
	exit(status);
}
