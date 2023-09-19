#include "shell.h"
/**
 * clear_environ - free the shell's environment
 * @myenv: shell's environment
 *
 * Return: void
 */

void clear_environ(char **myenv)
{
	unsigned int j;

	for (j = 0; myenv[j] != NULL; j++)
	{
		free(myenv[j]);
	}
	free(myenv);
}

