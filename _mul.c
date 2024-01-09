#include "monty.h"
/**
 * _mul - Multiplies the second top element of the stack with the top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty file where the instruction appears.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = sum;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
