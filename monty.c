#include "monty.h"

void main(int argc, char **argv)
{
    stack_t *stack = NULL;
    if (argc != 2)
    {
        fprintf(stderr, ARGUMENT_NOT_CORRECT);
        exit(EXIT_FAILURE);
    }
    if (strcmp(argv[1], "push") == 0)
        push(&stack, 3);
    exit(EXIT_SUCCESS);
}