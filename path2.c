#include "shell.h"
/**
 * mypath_check - checks if the command is in the PATH
 * @myvars: variables
 *
 * Return: void
 */
void mypath_check(vars_t *myvars)
{
	char *the_path, *path_dup = NULL, *checker = NULL;
	unsigned int j = 0, k = 0;
	char **token_path;
	struct stat buff;

	if (mydir_check(myvars->av[0]))
		k = mycwd_exe(myvars);
	else
	{
		the_path = mypath_find(myvars->env);
		if (the_path != NULL)
		{
			path_dup = my_strdup(the_path + 5);
			token_path = my_tkenizer(path_dup, ":");
			for (j = 0; token_path && token_path[j]; j++, free(checker))
			{
				checker = my_strcat(token_path[j], myvars->av[0]);
				if (stat(checker, &buff) == 0)
				{
					k = mypath_exe(checker, myvars);
					free(checker);
					break;
				}
			}
			free(path_dup);
			if (token_path == NULL)
			{
				myvars->status = 127;
				my_exit(myvars);
			}
		}
		if (the_path == NULL || token_path[j] == NULL)
		{
			myerror_print(myvars, ": not found\n");
			myvars->status = 127;
		}
		free(token_path);
	}
	if (k == 1)
		my_exit(myvars);
}

