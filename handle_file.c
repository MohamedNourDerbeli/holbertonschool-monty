#include "monty.h"
/**
 * file - Reads and executes commands from a file.
 * @file: File name to be read.
 * @stack: Pointer to the top of the stack.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 **/
int file(char *file, stack_t **stack)
{
	size_t len;
	ssize_t ret;
	unsigned int line_number = 0;
	char *line = NULL;
	char *cmd, *delim = "$\n \t\r";
	FILE *of;

	of = fopen(file, "r");
	if (file == NULL || of == NULL)
	{
		fprintf(stderr, FILE_NOT_OPEN, file);
		exit(EXIT_FAILURE);
	}
	atexit(free_node);
	while ((ret = getline(&line, &len, of)) != -1)
    {
        line_number++;
        if (ret == -1)
        {
                fprintf(stderr, FILE_NOT_OPEN, file);
                fclose(of);
                free(line);
                exit(EXIT_FAILURE);
        }

        cmd = strtok(line, delim);
        if (cmd != NULL)
            opcode(stack, cmd, line_number);
    }
    free(line);
    fclose(of);
    exit(EXIT_SUCCESS);
}
