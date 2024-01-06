#include "monty.h"
/**
 * _pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecode file.
 **/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	(*stack) = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}
