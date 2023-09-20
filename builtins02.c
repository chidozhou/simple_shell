#include "shell.h"

/**
 * my_env - Print the current environment variables.
 * @myvars: A struct containing environment data.
 *
 * Description:
 * This function prints the current environment stndard output.
 *
 * Return: void
 */
void my_env(vars_t *myvars)
{
	/* Initialize a counter for iterating through the environment */
	unsigned int j = 0;

	/* Loop until reaching the end of the environment array */
	while (myvars->env[j])
	{
		/* Print the current environment variable */
		my_puts(myvars->env[j]);

		/* Print a newline character to separate variables */
		my_puts("\n");
		j++;
	}
	/* Set the status to indicate success */
	myvars->status = 0;
}

