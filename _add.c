#include "monty.h"
/**
 * _add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecode file.
 **/
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
