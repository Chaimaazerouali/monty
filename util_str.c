#include "monty.h"

/**
 * _strlen - calculates length of a string
 * @s: String
 * Return: Number of characters in string
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count++])
		;

	return (count - 1);
}

/**
 * _strdup - allocates memory for a copy of a string
 * @s: String
 * Return: Pointer to new string or NULL
 */
char *_strdup(char *s)
{
	int len, i;
	char *dest;

	if (!s)
		return (0);

	len = _strlen(s);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);

	i = -1;
	while (s[++i])
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * str_numeric - allocates memory for a copy of a string
 * @str: String to process
 *
 * Return: Pointer to new string or NULL
 */
int str_numeric(char *str)
{
	int i = -1;

	if (!str)
		return (0);

	while (str[++i])
		if (!isdigit(str[i]))
			return (0);
	return (1);
}
