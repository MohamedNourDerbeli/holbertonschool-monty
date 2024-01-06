#include "monty.h"
/**
 * _pall - Prints all the values on the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecode file
 **/
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node = *stack;

	if (stack == NULL)
		return;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
