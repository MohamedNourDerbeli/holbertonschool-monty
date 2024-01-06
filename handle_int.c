#include "monty.h"
/**
 * _strtol - Converts a string to a long integer.
 * @op: The string to be converted.
 * @line_number: Line number in the Monty bytecode file.
 * Return: The converted long integer.
 **/
int _strtol(char *op, unsigned int line_number)
{
	char *ptr;
	long ret;

	ret = strtol(op, &ptr, 10);
	if (ret == LONG_MAX || ret == LONG_MIN)
		exit(EXIT_FAILURE);

	if (op == ptr)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (ret);
}
