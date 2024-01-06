#include "monty.h"
glob_t glob;

/**
 * stack_init - initialize all the things
 * @head: top of stack data structure
 **/
void stack_init(stack_t **head)
{
	*head = NULL;
	glob.top = head;
}
/**
 * free_node - free all malloc'ed memory
 *     note: this is available "atexit", starting at
 *           getline loop
 **/
void free_node(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(glob.top);
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
