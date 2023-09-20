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

	/* Check if the command is "exit" and if an exit status is provided */
	while (my_strcmpr(myvars->av[0], "exit") == 0 && myvars->av[1] != NULL)
	{
		/* Convert the exit status argument to an integer */
		exit_status = my_atoi(myvars->av[1]);

		/* If the exit status is -1 (invalid) 2 and display an error msg */
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

		/* Set the program's exit status to the specified value and break the loop */
		myvars->status = exit_status;
		break;
	}

	/* Free allocated memory and exit the program */
	free(myvars->buffer);
	free(myvars->av);
	free(myvars->commands);
	clear_environ(myvars->env);
	exit(myvars->status);
}

