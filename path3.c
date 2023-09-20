#include "shell.h"

/**
 * mycwd_exe - executes the command in the current working directory
 * @myvars: pointer to struct of variables
 *
 * Return: 0 on success, 1 on failure
 */
int mycwd_exe(vars_t *myvars)
{
	struct stat buff;
	pid_t c_pid;

	if (stat(myvars->av[0], &buff) != 0)
	{
		myerror_print(myvars, ": not found\n");
		myvars->status = 127;
		return (0);
	}
	if (access(myvars->av[0], X_OK) != 0)
	{
		myerror_print(myvars, ": Permission denied\n");
		myvars->status = 126;
		return (0);
	}

	c_pid = fork();
	if (c_pid == -1)
	{
		myerror_print(myvars, NULL);
		return (1);
	}
	if (c_pid == 0)
	{
		if (execve(myvars->av[0], myvars->av, myvars->env) == -1)
			myerror_print(myvars, NULL);
	}
	else
	{
		wait(&myvars->status);
		if (WIFEXITED(myvars->status))
			myvars->status = WEXITSTATUS(myvars->status);
		else if (WIFSIGNALED(myvars->status) && WTERMSIG(myvars->status) == SIGINT)
		{
			myvars->status = 130;
		}
	}

	return (0);
}
