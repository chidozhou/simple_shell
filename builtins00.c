#include "shell.h"

/**
 * my_checkbins - checks if the command is a builtin
 * @myvars: variables
 *
 * Return: pointer to the function or NULL
 */
void (*my_checkbins(vars_t *myvars))(vars_t *myvars)
{
	my_bins check[] = {
		{"exit", my_exit},
		{"env", my_env},
		{"setenv", myset_environ},
		{"unsetenv", myunset_environ},
		{NULL, NULL}
	};

	unsigned int j = 0;

	while (check[j].name != NULL)
	{
		if (my_strcmpr(myvars->av[0], check[j].name) == 0)
		{
			check[j].f(myvars);
			return (check[j].f);
		}
		j++;
	}

	return (NULL);
}

