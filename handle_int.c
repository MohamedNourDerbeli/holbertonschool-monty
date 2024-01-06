#include "monty.h"
#include <limits.h>

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


	if (*ptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	return (ret);
}
