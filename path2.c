#include "shell.h"

/**
 * mypath_check - checks if the command is in the PATH
 * @myvars: variables
 *
 * Return: void
 */
void mypath_check(vars_t *myvars)
{
	char *the_path = NULL;
	char **token_path = NULL;
	char *checker = NULL;
	struct stat buff;
	int found = 0;
	unsigned int j;

	if (mydir_check(myvars->av[0])
		{
			mycwd_exe(myvars);
			return;
		}

		the_path = mypath_find(myvars->env);
		if (the_path == NULL)
		{
			myerror_print(myvars, ": not found\n");
			myvars->status = 127;
			my_exit(myvars);
		}

		token_path = my_tkenizer(the_path + 5, ":");
		for (j = 0; token_path[j]; j++)
		{
			checker = my_strcat(token_path[j], myvars->av[0]);
			if (stat(checker, &buff) == 0)
			{
				found = 1;
				break;
			}
			free(checker);
		}
	free(token_path);
	if (!found)
	{
		myerror_print(myvars, ": not found\n");
		myvars->status = 127;
		my_exit(myvars);
	}
	mypath_exe(checker, myvars);
}

