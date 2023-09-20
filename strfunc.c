#include "shell.h"

/**
 * my_puts - writes a string to standard output
 * @strng: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t my_puts(char *strng)
{
	ssize_t number = my_strlen(strng);
	ssize_t length = write(STDOUT_FILENO, strng, number);

	if (length != number)
	{
		perror("Fatal Error");
		return (-1);
	}

	return (length);
}



/**
 * my_strdup - Duplicate a string.
 * @mystrtodup: The string to duplicate.
 *
 * Return: A pointer to the duplicated str
 */
char *my_strdup(char *mystrtodup)
{
	size_t length;
	char *the_copy;
	size_t i;

	if (mystrtodup == NULL)
	{
		return (NULL);
	}

	length = strlen(mystrtodup);
	the_copy = malloc((length + 1) * sizeof(char));
	if (the_copy == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= length; i++)
	{
		the_copy[i] = mystrtodup[i];
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
	size_t length1;
	size_t length2;
	size_t n_length;
	size_t j;
	size_t i;

	char *new_str;

	if (mystrc1 == NULL || mystrc2 == NULL)
	{
		return (NULL);
	}

	length1 = strlen(mystrc1);
	length2 = strlen(mystrc2);
	n_length = length1 + length2 + 2;

	new_str = malloc(n_length * sizeof(char));
	if (new_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < length1; i++)
	{
		new_str[i] = mystrc1[i];
	}
	new_str[length1] = '/';

	for (j = 0; j < length2; j++)
	{
		new_str[length1 + 1 + j] = mystrc2[j];
	}

	new_str[n_length - 1] = '\0';

	return (new_str);
}

