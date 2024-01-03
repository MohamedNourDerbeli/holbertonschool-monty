#include "monty.h"

void main(int argc, char **argv)
{
    stack_t *stack;
    if (argc != 2)
    {
        fprintf(stderr, ARGUMENT_NOT_CORRECT);
        exit(EXIT_FAILURE);
    }
    file(argv[1], &stack);
    exit(EXIT_SUCCESS);
}