#include "shell.h"
/**
 * my_env - prints the current environment
 * @myvars: struct of variables
 *
 * Return: void.
 */
void my_env(vars_t *myvars)
{
	unsigned int j;

	for (j = 0; myvars->env[j]; j++)
	{
		my_puts(myvars->env[j]);
		my_puts("\n");
	}
	myvars->status = 0;
}

