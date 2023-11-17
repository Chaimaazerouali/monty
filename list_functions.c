#include "monty.h"

/**
 * create_N - Allocates and initializes a new node.
 * @num: The numerical value to be stored in the node.
 * Return: A pointer to the newly created node, or NULL on failure.
 */
stack_t *create_N(int num)
{
    stack_t *n;

    n = malloc(sizeof(stack_t));
    if (n == NULL)
        handle_error(4);
    n->next = NULL;
    n->prev = NULL;
    n->n = num;
    return (n);
}

/**
 * free_stack_nod - Frees all nodes in the stack
 * Return: None.
 */
void free_stack_nod()
{
	stack_t *h;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		h = head;
		head = head->next;
		free(h);
	}
}
