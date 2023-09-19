#include "shell.h"
/**
 * myunset_environ - remove an environment variable
 * @myvars: pointer to a struct of variables
 *
 * Return: void
 */
void myunset_environ(vars_t *myvars)
{
	char **key, **n_environ;

	unsigned int k, j;

	if (myvars->av[1] == NULL)
	{
		myerror_print(myvars, ": Incorrect number of arguments\n");
		myvars->status = 2;
		return;
	}
	key = mykey_find(myvars->env, myvars->av[1]);
	if (key == NULL)
	{
		myerror_print(myvars, ": No variable to unset");
		return;
	}
	for (k = 0; myvars->env[k] != NULL; k++)
		;
	n_environ = malloc(sizeof(char *) * k);
	if (n_environ == NULL)
	{
		myerror_print(myvars, NULL);
		myvars->status = 127;
		my_exit(myvars);
	}
	for (k = 0; myvars->env[k] != *key; k++)
	{
		n_environ[k] = myvars->env[k];
	}
	for (j = k + 1; myvars->env[j] != NULL; j++, k++)
		n_environ[k] = myvars->env[j];
	n_environ[k] = NULL;
	free(*key);
	free(myvars->env);
	myvars->env = n_environ;
	myvars->status = 0;
}

