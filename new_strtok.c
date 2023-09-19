#include "shell.h"

/**
 * check_match - checks if a character matches any in a string
 * @c: character to check
 * @str: string to check
 *
 * Return: 1 if match, 0 if not
 */

unsigned int check_match(char c, const char *str)
{
	unsigned int j;

	for (j = 0; str[j] != '\0'; j++)
	{
		if (c == str[j])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * my_strtok - custom strtok
 * @mystr: string to tokenize
 * @mydelim: delimiter to tokenize against
 *
 * Return: pointer to the next token or NULL
 */
char *my_strtok(char *mystr, const char *mydelim)
{
	static char *start_token;
	static char *token_next;
	unsigned int j;

	if (mystr != NULL)
		token_next = mystr;
	start_token = token_next;
	if (start_token == NULL)
		return (NULL);
	for (j = 0; token_next[j] != '\0'; j++)
	{
		if (check_match(token_next[j], mydelim) == 0)
		{
			break;
		}
	}
	if (token_next[j] == '\0' || token_next[j] == '#')
	{
		token_next = NULL;
		return (NULL);
	}
	start_token = token_next + j;
	token_next = start_token;
	for (j = 0; token_next[j] != '\0'; j++)
	{
		if (check_match(token_next[j], mydelim) == 1)
			break;
	}
	if (token_next[j] == '\0')
	{
		token_next = NULL;
	}
	else
	{
		token_next[j] = '\0';
		token_next = token_next + j + 1;
		if (*token_next == '\0')
			token_next = NULL;
	}
	return (start_token);
}

