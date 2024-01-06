#include "monty.h"
/**
 * _add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecode file.
 **/
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, sum;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	sum = h->n + h->next->n;
	h->next->n = sum;
	*stack = h->next;
	free(h);
	(*stack)->prev = NULL;
}
