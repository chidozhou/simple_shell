#include "shell.h"
/**
 * mypath_exe - executes a command in the path
 * @mycommand: full path to the command
 * @myvars: pointer to struct of variables
 *
 * Return: 0 on success, 1 on failure
 */
int mypath_exe(char *mycommand, vars_t *myvars)
{
	pid_t c_pid;

	if (access(mycommand, X_OK) == 0)
	{
		c_pid = fork();
		if (c_pid == -1)
			myerror_print(myvars, NULL);
		if (c_pid == 0)
		{
			if (execve(mycommand, myvars->av, myvars->env) == -1)
				myerror_print(myvars, NULL);
		}
		else
		{
			wait(&myvars->status);
			if (WIFEXITED(myvars->status))
			{
				myvars->status = WEXITSTATUS(myvars->status);
			}
			else if (WIFSIGNALED(myvars->status) && WTERMSIG(myvars->status) == SIGINT)
			{
				myvars->status = 130;
			}
			return (0);
		}
		myvars->status = 127;
		return (1);
	}
	else
	{
		myerror_print(myvars, ": Permission denied\n");
		myvars->status = 126;
	}
	return (0);
}

