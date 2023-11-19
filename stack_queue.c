#include "monty.h"

/**
 * addto_stack - Inserts a new node into the stack.
 * @n_nod: Pointer to the new node.
 * @l: Integer representing the line number corresponding to the opcode.
 */
void addto_stack(stack_t **n_nod, __attribute__((unused)) unsigned int l)
{
	stack_t *temp;

	if (n_nod == NULL || *n_nod == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *n_nod;
		return;
	}

	temp = head;
	head = *n_nod;
	head->next = temp;
	temp->prev = head;
}
/**
 * addto_queue - Enqueues a node in the queue.
 * @n_nod: Pointer to the new node.
 * @l: Integer representing the line number associated with the opcode.
 */
void addto_queue(stack_t **n_nod, __attribute__((unused)) unsigned int l)
{
	stack_t *temp;

	if (n_nod == NULL || *n_nod == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *n_nod;
		return;
	}

	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *n_nod;
	(*n_nod)->prev = temp;
}
