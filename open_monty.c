#include "monty.h"
/**
 * open_monty - Opens a file with a specified file path
 * @filePath: The file path to be opened
 * Return: void
 */

void open_monty(char *filePath)
{
    FILE *file = fopen(filePath, "r");

    if (filePath == NULL || file == NULL)
        handle_error(2, filePath);

    readFile(file);
    fclose(file);
}


/**
 * pall_stk - Print all elements of the stack
 * @stk: Double pointer to the head of the doubly linked list representing the stack
 * @line_num: Current line number in the Monty file
 * Return: void
 */
void pall_stk(stack_t **stk, __attribute__((unused)) unsigned int line_num)
{
    stack_t *top_elements = *stk;

    /* Check if the stack is empty or NULL */
    if (stk == NULL || *stk == NULL)
    {
        return;
    }

    /* Traverse the stack and print each element */
    while (top_elements)
    {
        printf("%d\n", top_elements->n);
        top_elements = top_elements->next;
    }
}

