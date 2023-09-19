#include "shell.h"
/**
 * my_strlen - returns the length of a string
 * @strng: string to be measured
 * Return: length of string
 */
unsigned int my_strlen(char *strng)
{
	unsigned int length;

	length = 0;

	for (length = 0; strng[length]; length++)
		;
	return (length);
}

/**
 * my_strcmpr - compares two strings
 * @mystrcmp1: first string, of two, to be compared in length
 * @mystrcmp2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */
int my_strcmpr(char *mystrcmp1, char *mystrcmp2)
{
	int j;

	j = 0;
	while (mystrcmp1[j] == mystrcmp2[j])
	{
		if (mystrcmp1[j] == '\0')
		{
			return (0);
		}
		j++;
	}
	return (mystrcmp1[j] - mystrcmp2[j]);
}

