#include "monty.h"
/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Number of command line arguments.
 * @argv: Array of strings containing the command line arguments.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 **/
int main(int argc, char **argv)
{
	stack_t *head;
	
	stack_init(&head);
	if (argc != 2)
	{
		fprintf(stderr, ARGUMENT_NOT_CORRECT);
		exit(EXIT_FAILURE);
	}
	file(argv[1], &head);
	exit(EXIT_SUCCESS);
}
