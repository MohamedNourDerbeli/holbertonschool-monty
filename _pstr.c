#include "monty.h"
/**
 * _pstr - Prints the string contained in the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty file where the instruction appears.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;
	(void)line_number;

	if (*stack == NULL)
	{
		putchar('\n');
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		n = tmp->n;
		if (n <= 0 || n > 127)
			break;
		putchar(n);
		tmp = tmp->next;
	}
	putchar('\n');
	exit(EXIT_SUCCESS);
}
