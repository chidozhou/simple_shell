#include "shell.h"
/**
 * my_exit - Exit the program with a specified status code
 * @myvars: Variables containing command and status
 *
 * Return: void
 */
void my_exit(vars_t *myvars)
{
	int exit_status;

	if (my_strcmpr(myvars->av[0], "exit") == 0 && myvars->av[1] != NULL)
	{
		exit_status = my_atoi(myvars->av[1]);
		if (exit_status == -1)
		{
			myvars->status = 2;
			myerror_print(myvars, ": Illegal number: ");
			myputs2(myvars->av[1]);
			myputs2("\n");
			free(myvars->commands);
			myvars->commands = NULL;
			return;
		}
		myvars->status = exit_status;
	}
	free(myvars->buffer);
	free(myvars->av);
	free(myvars->commands);
	clear_environ(myvars->env);
	exit(myvars->status);
}

