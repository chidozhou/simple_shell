#include "shell.h"

/**
 * my_puts - writes a string to standard output
 * @strng: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t my_puts(char *strng)
{
	ssize_t number, length;

	number = my_strlen(strng);
	length = write(STDOUT_FILENO, strng, number);
	if (length != number)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (length);
}

/**
 * my_strdup - returns pointer to new mem alloc space which contains the_copy
 * @mystrtodup: string to be duplicated
 *
 * Return: a pointer to the new duplicated string
 */
char *my_strdup(char *mystrtodup)
{
	char *the_copy;

	int length, j;

	if (mystrtodup == 0)
	{
		return (NULL);
	}

	for (length = 0; mystrtodup[length]; length++)
		;
	the_copy = malloc((length + 1) * sizeof(char));

	for (j = 0; j <= length; j++)
	{
		the_copy[j] = mystrtodup[j];
	}
	return (the_copy);
}


/**
 * my_strcat - concatenates two strings
 * @mystrc1: first string
 * @mystrc2: second string
 * Return: pointer
 */

char *my_strcat(char *mystrc1, char *mystrc2)
{
	char *new_str;
	unsigned int length1, length2, n_length, k, j;

	length1 = 0;
	length2 = 0;
	if (mystrc1 == NULL)
	{
		length1 = 0;
	}
	else
	{
		for (length1 = 0; mystrc1[length1]; length1++)
			;
	}
	if (mystrc2 == NULL)
		length2 = 0;
	else
	{
		for (length2 = 0; mystrc2[length2]; length2++)
			;
	}
	n_length = length1 + length2 + 2;
	new_str = malloc(n_length * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	for (k = 0; k < length1; k++)
	{
		new_str[k] = mystrc1[k];
	}
	new_str[k] = '/';
	for (j = 0; j < length2; j++)
		new_str[k + 1 + j] = mystrc2[j];
	new_str[length1 + length2 + 1] = '\0';
	return (new_str);
}

