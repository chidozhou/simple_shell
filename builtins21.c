#include "shell.h"

/**
 * mykey_find - finds an environment variable
 * @myenv: array of environment variables
 * @mykey: environment variable to find
 *
 * Return: pointer to address of the environment variable
 */
char **mykey_find(char **myenv, char *mykey)
{
	unsigned int k, j, length;

	length = my_strlen(mykey);
	for (k = 0; myenv[k] != NULL; k++)
	{
		for (j = 0; j < length; j++)
			if (mykey[j] != myenv[k][j])
			{
				break;
			}
		if (j == length && myenv[k][j] == '=')
		{
			return (&myenv[k]);
		}
	}
	return (NULL);
}

