#include "shell.h"

/**
 * myvalue_add - create a new environment variable string
 * @mykey: variable name
 * @myvalue: variable value
 *
 * Return: pointer to the new string;
 */
char *myvalue_add(char *mykey, char *myvalue)
{
	unsigned int length1, length2, k, j;
	char *n_environ;

	length1 = my_strlen(mykey);
	length2 = my_strlen(myvalue);
	n_environ = malloc(sizeof(char) * (length1 + length2 + 2));
	if (n_environ == NULL)
	{
		return (NULL);
	}
	for (k = 0; mykey[k] != '\0'; k++)
	{
		n_environ[k] = mykey[k];
	}
	n_environ[k] = '=';
	for (j = 0; myvalue[j] != '\0'; j++)
	{
		n_environ[k + 1 + j] = myvalue[j];
	}
	n_environ[k + 1 + j] = '\0';
	return (n_environ);
}

