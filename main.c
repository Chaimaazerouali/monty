#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point of the Monty interpreter.
 * @arg_count: Number of command-line arguments.
 * @arg_vector: Array of command-line argument strings.
 * Return: void.
 *
 */
int main(int arg_count, char *arg_vector[])
{
    if (arg_count != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    open_monty(arg_vector[1]);
    free_stack_nod();
    return (0);
}

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
void free_stack_nod(void)
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
