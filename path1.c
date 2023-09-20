#include "shell.h"
#include <string.h>

/**
 * mypath_find - finds the PATH variable
 * @myenv: array of environment variables
 *
 * Return: pointer to the node that contains the PATH, or NULL on failure
 */
char *mypath_find(char **myenv)
{
	char *path_variable = "PATH=";
	size_t path_len = strlen(path_variable);
	size_t i;

	if (myenv == NULL)
		return (NULL);

	while (*myenv)
	{
		char *env_var = *myenv;

		for (i = 0; env_var[i] != '\0' && i < path_len; i++)
		{
			if (env_var[i] != path_variable[i])
				break;
		}

		if (i == path_len)
		{
			return (env_var);
		}

		myenv++;
	}
	return (NULL);
}
