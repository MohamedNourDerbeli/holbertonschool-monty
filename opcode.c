#include "monty.h"

void opcode(stack_t **stack, char *cmd, unsigned int line_number)
{
    int i = 0;
    instruction_t ops[] = {
        {"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {NULL, NULL}};
    for (i = 0; ops[i].opcode; i++)
    {
        if (strcmp(ops[i].opcode, cmd) == 0)
        {
            ops[i].f(stack, line_number);
            return;
        }
    }
    if (strlen(cmd)!=0)
    {
        fprintf(stderr, INVAILD_INSTRUCTION, line_number, cmd);
        exit(EXIT_FAILURE);
    }
}