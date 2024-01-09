#include "monty.h"
/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty file where the instruction appears.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n / (*stack)->next->n;
	(*stack)->next->n = sum;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
