#include "monty.h"
/**
 * _pall - Prints all the values on the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecode file
 **/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = *stack;
	if (node == NULL)
		return;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
