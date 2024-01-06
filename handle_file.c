#include "monty.h"

#define DELIMITERS "$\n \t\r"

/**
 * file - Reads and executes commands from a file.
 * @file: File name to be read.
 * @stack: Pointer to the top of the stack.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 **/
int file(char *file, stack_t **stack)
{
	size_t len = 0;
	ssize_t ret;
	unsigned int line_number = 0;
	char *line = NULL;
	char *cmd;
	FILE *of;

	if (file == NULL)
	{
		fprintf(stderr, FILE_NOT_OPEN, file);
		exit(EXIT_FAILURE);
	}
	of = fopen(file, "r");
	if (of == NULL)
	{
		fprintf(stderr, FILE_NOT_OPEN, file);
		exit(EXIT_FAILURE);
	}
	atexit(free_node);
	while ((ret = getline(&line, &len, of)) != -1)
	{
		line_number++;
		cmd = strtok(line, DELIMITERS);

		if (cmd != NULL)
			opcode(stack, cmd, line_number);
	}
	if (ret == -1)
	{
		fprintf(stderr, FILE_NOT_OPEN, file);
		fclose(of);
		free(line);
		exit(EXIT_FAILURE);
	}

	free(line);
	fclose(of);
	exit(EXIT_SUCCESS);
}
