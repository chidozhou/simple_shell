#include "shell.h"

/**
 * mypath_check - checks if the command is in the PATH
 * @myvars: variables
 *
 * Return: void
 */
void mypath_check(vars_t *myvars)
{
	char *path;
	char **paths;
	int i;

	if (mydir_check(myvars->av[0]))
	{
		mycwd_exe(myvars);
		return;
	}

	path = mypath_find(myvars->env);
	if (path == NULL)
	{
		myerror_print(myvars, ": PATH environment variable is not set\n");
		myvars->status = 127;
		my_exit(myvars);
	}

	paths = my_tkenizer(path, ":");
	for (i = 0; paths && paths[i]; i++)
	{
		char *full_path = my_strcat(paths[i], myvars->av[0]);

		struct stat buff;

		if (stat(full_path, &buff) == 0)
		{
			mypath_exe(full_path, myvars);
			free(full_path);
			break;
		}
		free(full_path);
	}
	free(paths);
	if (paths[i] == NULL)
	{
		myerror_print(myvars, ": not found\n");
		myvars->status = 127;
		my_exit(myvars);
	}
}

