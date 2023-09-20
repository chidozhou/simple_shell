#include "shell.h"

/**
 * myputs2 - prints a string to standard error
 * @mystr: string to print
 */
void myputs2(char *mystr)
{
	ssize_t length;

	char *current = mystr;

	while (*current)
	{
		length = write(STDERR_FILENO, current, 1);

		if (length != 1)
		{
			perror("Fatal Error");
			exit(1);
		}

		current++;
	}
}
