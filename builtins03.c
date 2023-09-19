#include "shell.h"
/**
 * myset_environ - create a new environ variable, or edit an existing var
 * @myvars: pointer to struct of variables
 *
 * Return: void
 */
void myset_environ(vars_t *myvars)
{
	char **the_key;
	char *v;

	if (myvars->av[1] == NULL || myvars->av[2] == NULL)
	{
		myerror_print(myvars, ": Incorrect number of arguments\n");
		myvars->status = 2;
		return;
	}
	the_key = mykey_find(myvars->env, myvars->av[1]);
	if (the_key == NULL)
	{
		mykey_add(myvars);
	}
	else
	{
		v = myvalue_add(myvars->av[1], myvars->av[2]);
		if (v == NULL)
		{
			myerror_print(myvars, NULL);
			free(myvars->buffer);
			free(myvars->commands);
			free(myvars->av);
			clear_environ(myvars->env);
			exit(127);
		}
		free(*the_key);
		*the_key = v;
	}
	myvars->status = 0;
}

