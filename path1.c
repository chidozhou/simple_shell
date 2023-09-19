#include "shell.h"
/**
 * mypath_find - finds the PATH variable
 * @myenv: array of environment variables
 *
 * Return: pointer to the node that contains the PATH, or NULL on failure
 */
char *mypath_find(char **myenv)
{
	char *path = "PATH=";
	unsigned int i, j;

	for (i = 0; myenv[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != myenv[i][j])
			{
				break;
			}
		if (j == 5)
		{
			break;
		}
	}
	return (myenv[i]);
}

