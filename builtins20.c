#include "shell.h"

/**
 * mykey_add - create a new environment variable
 * @myvars: pointer to struct of variables
 *
 * Return: void
 */
void mykey_add(vars_t *myvars)
{
	unsigned int j;
	char **n_environ;

	for (j = 0; myvars->env[j] != NULL; j++)
		;
	n_environ = malloc(sizeof(char *) * (j + 2));
	if (n_environ == NULL)
	{
		myerror_print(myvars, NULL);
		myvars->status = 127;
		my_exit(myvars);
	}
	for (j = 0; myvars->env[j] != NULL; j++)
	{
		n_environ[j] = myvars->env[j];
	}
	n_environ[j] = myvalue_add(myvars->av[1], myvars->av[2]);
	if (n_environ[j] == NULL)
	{
		myerror_print(myvars, NULL);
		free(myvars->buffer);
		free(myvars->commands);
		free(myvars->av);
		clear_environ(myvars->env);
		free(n_environ);
		exit(127);
	}
	n_environ[j + 1] = NULL;
	free(myvars->env);
	myvars->env = n_environ;
}

