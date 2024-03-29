#include "monty.h"
/**
 * _push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecode file.
 **/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));
	char *op;
	char *delims = "$\n \t\r";
	int num;

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, delims);
	if (stack == NULL || op == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = _strtol(op, line_number);
	node->n = num;
	node->prev = NULL;
	node->next = *stack;
	if (node->next != NULL)
		(node->next)->prev = node;
	*stack = node;
}
