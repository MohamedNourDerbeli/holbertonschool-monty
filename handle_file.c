#include "monty.h"
int file(char *file, stack_t **stack)
{
    FILE *of;
    size_t len, ret;
    unsigned int line_number = 0;
    char *line = NULL;
    char *cmd, *delim = "\n \t\r";

    if (!file)
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
    while ((ret = getline(&line, &len, of) != -1))
    {
        cmd = strtok(line, delim);
        line_number++;
        if (cmd)
            opcode(stack, cmd, line_number);
    }
    free(line);
    fclose(of);
    return (EXIT_FAILURE);
}