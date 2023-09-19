#include "shell.h"

/**
 * myerror_print - prints error messages to standard error
 * @myvars: pointer to struct of variables
 * @mymsg: message to print out
 *
 * Return: void
 */
void myerror_print(vars_t *myvars, char *mymsg)
{
	char *count;

	myputs2(myvars->argv[0]);
	myputs2(": ");
	count = my_uitoa(myvars->count);
	myputs2(count);
	free(count);
	myputs2(": ");
	myputs2(myvars->av[0]);
	if (mymsg)
	{
		myputs2(mymsg);
	}
	else
		perror("");
}

/**
 * my_uitoa - converts an unsigned int to a string
 * @mycount: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *my_uitoa(unsigned int mycount)
{
	char *numstring;
	unsigned int temp, digit;

	temp = mycount;
	for (digit = 0; temp != 0; digit++)
	{
		temp /= 10;
	}
	numstring = malloc(sizeof(char) * (digit + 1));
	if (numstring == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstring[digit] = '\0';
	for (--digit; mycount; --digit)
	{
		numstring[digit] = (mycount % 10) + '0';
		mycount /= 10;
	}
	return (numstring);
}

