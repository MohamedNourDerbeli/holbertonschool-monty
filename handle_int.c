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

	errno = 0;
	ret = strtol(op, &ptr, 10);
	if ((errno == ERANGE && (ret == LONG_MAX || ret == LONG_MIN))
				|| (errno != 0 && ret == 0))
		exit(EXIT_FAILURE);

	if (ptr == op)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (op[0] != '\0')
		if (*ptr != '\0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	return (ret);
}
