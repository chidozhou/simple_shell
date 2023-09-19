#include "shell.h"
/**
 * mydir_check - checks if the command is a part of a path
 * @mystr: command
 *
 * Return: 1 on success, 0 on failure
 */
int mydir_check(char *mystr)
{
	unsigned int j;

	for (j = 0; mystr[j]; j++)
	{
		if (mystr[j] == '/')
		{
			return (1);
		}
	}
	return (0);
}

