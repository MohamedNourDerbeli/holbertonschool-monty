#include "monty.h"
/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Number of command line arguments.
 * @argv: Array of strings containing the command line arguments.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 **/
void main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, ARGUMENT_NOT_CORRECT);
		exit(EXIT_FAILURE);
	}
	file(argv[1], &stack);
	exit(EXIT_SUCCESS);
}
