#include "monty.h"
/**
 * find_fc - Finds the appropriate function for the opcode
 * @o: Opcode
 * @a: Argument of opcode
 * @l: Line number
 * @f: Storage format (0 for stack, 1 for queue)
 * Return: void
 */
void find_fc(char *o, char *a, int l, int f)
{
	int i;
	int g;

	instruction_t ops[] = {
		{"push", addto_stack},
		{"pall", pall_stk},
		{"pint", pint_elements},
		{"pop", pop_elements},
		{"nop", do_nothing},
		{"swap", swap_elements},
		{"add", add_elements},
		{"sub", subtract_elements},
		{"div", divide_elements},
		{"mul", multiply_elements},
		{"mod", modulo_elements},
		{"pchar", printAscii},
		{"pstr", printStringStack},
		{"rotl", rot_lift},
		{"rotr", rot_right},
		{NULL, NULL}
	};
	if (o[0] == '#')
		return;

	for (g = 1, i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(o, ops[i].opcode) == 0)
		{
			call_fc(ops[i].f, o, a, l, f);
			g = 0;
		}
	}
	if (g == 1)
		handle_error(3, l, o);
}

/**
 * call_fc - Calls the required function.
 * @func: Pointer to the function to be called.
 * @o: String representing the opcode.
 * @a: String representing a numeric value.
 * @l: Line number for the instruction.
 * @f: Format specifier (0 for stack, 1 for queue).
 */
void call_fc(op_func func, char *o, char *a, int l, int f)
{
	stack_t *n;
	int flag;
	int i;

	flag = 1;
	if (strcmp(o, "push") == 0)
	{
		if (a != NULL && a[0] == '-')
		{
			a = a + 1;
			flag = -1;
		}
		if (a == NULL)
			handle_error(5, l);
		for (i = 0; a[i] != '\0'; i++)
		{
			if (!isdigit(a[i]))
				handle_error(5, l);
		}
		n = create_N(atoi(a) * flag);
		if (f == 0)
			func(&n, l);
		if (f == 1)
			addto_queue(&n, 1);
	}
	else
		func(&head, l);
}
