#include "monty.h"
/**
 * _add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecode file.
 **/
void _add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (stack == NULL || (*stack)->next == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n += tmp;
	(*stack)->prev = NULL;
}
