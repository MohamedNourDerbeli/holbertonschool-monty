#include "monty.h"
/**
 * opcode - Execute the corresponding operation based on the opcode.
 * @stack: Double pointer to the top of the stack.
 * @cmd: The opcode to be executed.
 * @line_number: Line number in the Monty bytecode file.
 **/
void opcode(stack_t **stack, char *cmd, unsigned int line_number)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"add", _add},
		{"swap", _swap},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}};

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(cmd, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}
	if (strlen(cmd) != 0 && cmd[0] != '#')
	{
		fprintf(stderr, INVAILD_INSTRUCTION, line_number, cmd);
		exit(EXIT_FAILURE);
	}
}
