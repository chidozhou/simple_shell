#include "shell.h"

/**
 * my_tkenizer - tokenizes a buffer with a delimiter
 * @buff: buffer to tokenize
 * @mydlimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the token
 */
char **my_tkenizer(char *buff, char *mydlimiter)
{
	char **token = NULL;
	size_t j = 0;
	size_t m_count = 10;

	if (buff == NULL)
	{
		return (NULL);
	}

	token = malloc(sizeof(char *) * m_count);
	if (token == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}

	for (; j < m_count; j++)
	{
		token[j] = my_strtok(buff, mydlimiter);
		if (token[j] == NULL)
			break;
		if (j == m_count - 1)
		{
			token = my_rllocat(token, &m_count);
			if (token == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buff = NULL;
	}

	return (token);
}

