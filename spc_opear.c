#include "monty.h"

/**
 * pop_elements - Removes the top element from the stack.
 * @stk: Pointer to a pointer pointing to the top element of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void pop_elements(stack_t **stk, unsigned int line_num)
{
	stack_t *top_element;

    if (stk == NULL || *stk == NULL)
        handle_error(7, line_num);

    top_element = *stk;
    *stk = top_element->next;
    if (*stk != NULL)
        (*stk)->prev = NULL;
    free(top_element);
}

/**
 * pint_elements - Prints the value of the top element of the stack.
 * @stk: Pointer to a pointer pointing to the top element of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void pint_elements(stack_t **stk, unsigned int line_num)
{
    if (stk == NULL || *stk == NULL)
        handle_error(6, line_num);
    printf("%d\n", (*stk)->n);
}

/**
 * rot_lift - Rotates the first node of the stack to the bottom.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void rot_lift(stack_t **stk, __attribute__((unused)) unsigned int line_num)
{
    stack_t *top_element;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        return;

    top_element = *stk;
    while (top_element->next != NULL)
        top_element = top_element->next;

    top_element->next = *stk;
    (*stk)->prev = top_element;
    *stk = (*stk)->next;
    (*stk)->prev->next = NULL;
    (*stk)->prev = NULL;
}

/**
 * rot_right - Rotates the last node of the stack to the top.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void rot_right(stack_t **stk, __attribute__((unused)) unsigned int line_num)
{
    stack_t *top_element;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        return;

    top_element = *stk;

    while (top_element->next != NULL)
        top_element = top_element->next;

    top_element->next = *stk;
    top_element->prev->next = NULL;
    top_element->prev = NULL;
    (*stk)->prev = top_element;
    (*stk) = top_element;
}
