#include "monty.h"

/**
 * parse_line - parses command
 * @line: command to parse
 *
 * Return: parsed command
 */
char **parse_line(char *line, instruction_t *operations, int line_number)
{
	int i = -1;
	char *line_copy = 0, *token = 0, *delimiters = " \n";
	char **tokens;

	line_copy = _strdup(line);
	if (!line_copy)
		return (0);
	token = strtok(line_copy, delimiters);

	if (!token || token[0] == '#')
		return (0);

	while (operations[++i].opcode)
		if (!strcmp(token, operations[i].opcode))
			break;

	if (!operations[i].opcode)
	{
		free(line_copy);
		handle_error(3, line_number, token);
	}
	tokens = malloc(sizeof(char *) * 2);
	if (!tokens)
	{
		free(line_copy);
		handle_error(4);
	}
	tokens[0] = _strdup(token);
	tokens[1] = _strdup(strtok(0, delimiters));
	free(line_copy);
	return (tokens);
}
