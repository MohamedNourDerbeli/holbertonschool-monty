#include "monty.h"
/**
 * _pstr - Prints the string contained in the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty file where the instruction appears.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || stack == NULL)
	{
		putchar('\n');
		exit(EXIT_FAILURE);
	}
	while ((*stack) != NULL)
	{
		n = (*stack)->n;
		if (n <= 0 || n > 127)
			break;
		putchar(n);
		(*stack) = (*stack)->next;
	}
	putchar('\n');
}
