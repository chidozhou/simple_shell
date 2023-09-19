#include "shell.h"
/**
 * myputs2 - prints a string to standard error
 * @mystr: string to print
 *
 * Return: void
 */
void myputs2(char *mystr)
{
	ssize_t number, length;

	number = my_strlen(mystr);
	length = write(STDERR_FILENO, mystr, number);
	if (length != number)
	{
		perror("Fatal Error");
		exit(1);
	}

}

