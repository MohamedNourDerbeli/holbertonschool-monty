#include "monty.h"
/**
 * _pchar - Prints the character at the top of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty file where the instruction appears.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(n);
	putchar('\n');
}
