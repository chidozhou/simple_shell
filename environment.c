#include "shell.h"

/**
 * create_environ - create shell environ from main arg
 * @myenv: environment passed to main
 *
 * Return: pointer to the new environment
 */

char **create_environ(char **myenv)
{
	char **new_environ = NULL;
	size_t j;

	for (j = 0; myenv[j] != NULL; j++)
		;
	new_environ = malloc(sizeof(char *) * (j + 1));
	if (new_environ == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (j = 0; myenv[j] != NULL; j++)
	{
		new_environ[j] = my_strdup(myenv[j]);
	}
	new_environ[j] = NULL;
	return (new_environ);
}

