#include "monty.h"

/**
 * open_file - opens monty file
 * @file_path: string representing path to monty file.
 *
 * Return: (FILE*) file stream or exits program if error
 */
FILE *open_file(char *file_path)
{
	FILE *file_stream = 0;

	file_stream = fopen(file_path, "r");
	if (!file_stream)
		handle_error(2, file_path);
	return (file_stream);
}

/**
 * process_file - gets each line from file and parse and execute it.
 * @file_path: string representing path to monty file.
 * @operations: array of available operations.
 *
 * Return: void
 */
void process_file(char *file_path, instruction_t *operations)
{
	FILE *file_stream = 0;
	char *line = 0;
	size_t len = 0;
	unsigned int lines_count = 0;
	char **tokens;

	file_stream = open_file(file_path);

	while (getline(&line, &len, file_stream) != -1)
	{
		tokens = parse_line(line, operations, ++lines_count);
		find_fc(tokens[0], tokens[1], lines_count, 0);
	}
	fclose(file_stream);
	free(line);
}
