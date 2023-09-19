#include "shell.h"

/**
 * my_checkbins - checks if the command is a builtin
 * @myvars: variables
 *
 * Return: pointer to the function or NULL
 */
void (*my_checkbins(vars_t *myvars))(vars_t *myvars)
{
	unsigned int j;
	my_bins check[] = {
		{"exit", my_exit},
		{"env", my_env},
		{"setenv", myset_environ},
		{"unsetenv", myunset_environ},
		{NULL, NULL}
	};

	for (j = 0; check[j].f != NULL; j++)
	{
		if (my_strcmpr(myvars->av[0], check[j].name) == 0)
		{
			break;
		}
	}
	if (check[j].f != NULL)
	{
		check[j].f(myvars);
	}
	return (check[j].f);
}

