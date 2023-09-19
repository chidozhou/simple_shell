#include "shell.h"

/**
 * my_atoi - converts a string into an integer
 * @mystr: string to convert
 *
 * Return: the integer value, or -1 if an error occurs
 */
int my_atoi(char *mystr)
{
	unsigned int j, digit;
	int number = 0, n_test;

	n_test = INT_MAX;
	for (digit = 0; n_test != 0; digit++)
	{
		n_test /= 10;
	}
	for (j = 0; mystr[j] != '\0' && j < digit; j++)
	{
		number *= 10;
		if (mystr[j] < '0' || mystr[j] > '9')
		{
			return (-1);
		}
		if ((j == digit - 1) && (mystr[j] - '0' > INT_MAX % 10))
		{
			return (-1);
		}
		number += mystr[j] - '0';
		if ((j == digit - 2) && (mystr[j + 1] != '\0') && (number > INT_MAX / 10))
		{
			return (-1);
		}
	}
	if (j > digit)
	{
		return (-1);
	}
	return (number);
}

