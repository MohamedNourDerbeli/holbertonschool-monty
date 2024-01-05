#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
    stack_t *node = malloc(sizeof(stack_t));
    char *op;
    char *DELIMS = "\n \t\r";
    if (node == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    op = strtok(NULL, DELIMS);
    if (stack == NULL || op == NULL)
    {
        fprintf(stderr, " usage: push integer\n");
        exit(EXIT_FAILURE);
    }
    node->n = line_number;
    node->prev = NULL;
    node->next = *stack;
    if (node->next != NULL)
        (node->next)->prev = node;
    *stack = node;
}
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *node = *stack;
    while (node != NULL)
    {
        printf("%d\n", node->n);
        node = node->next;
    }
}