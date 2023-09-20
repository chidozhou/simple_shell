#include "shell.h"
/**
 * my_strlen - returns the length of a string
 * @strng: string to be measured
 * Return: length of string
 */
unsigned int my_strlen(char *strng)
{
	unsigned int length = 0;

	while (strng[length] != '\0')
	{
		length++;
	}

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
	int j = 0;

	while (mystrcmp1[j] && mystrcmp2[j] && mystrcmp1[j] == mystrcmp2[j])
	{
		j++;
	}

	return (mystrcmp1[j] - mystrcmp2[j]);
}

