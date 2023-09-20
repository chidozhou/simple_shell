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
	char *count = my_uitoa(myvars->count);

	if (!count)
	{
		perror("my_uitoa failed");
		exit(EXIT_FAILURE);
	}

	myputs2(myvars->argv[0]);
	myputs2(": ");
	myputs2(count);
	myputs2(": ");
	myputs2(myvars->av[0]);

	if (mymsg)
	{
		myputs2(mymsg);
	}
	else
	{
		perror("");
	}

	free(count);
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
	int start = 0, end;

	if (mycount == 0)
	{
		numstring = malloc(sizeof(char) * 2);
		if (numstring == NULL)
		{
			perror("Fatal Error1");
			exit(127);
		}
		numstring[0] = '0';
		numstring[1] = '\0';
		return (numstring);
	}

	numstring = my_uitoa(mycount / 10);
	end = strlen(numstring) - 1;
	numstring = realloc(numstring, sizeof(char) * (strlen(numstring) + 2));
	if (numstring == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}

	/* Reverse the string */
	while (start < end)
	{
		char temp = numstring[start];

		numstring[start] = numstring[end];

		numstring[end] = temp;
		start++;
		end--;
	}

	return (numstring);
}
