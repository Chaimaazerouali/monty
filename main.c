#include "monty.h"
stack_t *head = 0;


/**
 * main - entry point for MontyBytecode interpreter
 * @argc: command line arguments count.
 * @argv: command line arguments values.
 *
 * Return: 0 on success, otherwise error.
 */
int main(int argc, char **argv)
{
	instruction_t operations[] = {
		{PALL_CODE, 0},
		{PUSH_CODE, 0},
/*		{PINT_CODE, 0},
		{POP_CODE, 0},
		{NOP_CODE, 0},
		{SWAP_CODE, 0},
		{ADD_CODE, 0},
		{SUB_CODE, 0},
		{DIV_CODE, 0},
		{MOD_CODE, 0},
		{MUL_CODE, 0},
		{PCHAR_CODE, 0},
		{PSTR_CODE, 0},
		{ROTL_CODE, 0},
		{ROTR_CODE, 0},		*/
		{0, 0}
	};

	if (argc != 2)
		handle_error(1);
	process_file(argv[1], operations);

	return (EXIT_SUCCESS);
}
