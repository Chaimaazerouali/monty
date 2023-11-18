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
/**
 * readFile - reads content from a file
 * @fdr: file descriptor pointer
 * Return: void
 */

void readFile(FILE *fdr)
{
    int line_num, fmt = 0;
    char *buf = NULL;
    size_t size = 0;

    for (line_num = 1; getline(&buf, &size, fdr) != -1; line_num++)
    {
        fmt = inter_line(buf, line_num, fmt);
    }
    free(buf);
}
/**
 * inter_line - Parses a line to determine the function to call.
 * @line: The line content from the file.
 * @line_num: The line number.
 * @fmt: Storage format: 0 for stack, 1 for queue.
 * Returns: 0 for stack opcode, 1 for queue opcode.
 */

int inter_line(char *line, int line_num, int fmt)
{
    char *opcode, *val;
    const char *delim = "\n ";

    if (line == NULL)
        handle_error(4);

    opcode = strtok(line, delim);
    if (opcode == NULL)
        return (fmt);
    val = strtok(NULL, delim);

    if (strcmp(opcode, "stack") == 0)
        return (0);
    if (strcmp(opcode, "queue") == 0)
        return (1);

    find_fc(opcode, val, line_num, fmt);
    return (fmt);
}


