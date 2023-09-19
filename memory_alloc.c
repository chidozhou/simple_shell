#include "shell.h"

/**
 * my_rllocat - reallocates a pointer to double the space
 * @myptr: pointer to the old array
 * @mysize: pointer to number of elements in the old array
 *
 * Return: pointer to the newsize array
 */

char **my_rllocat(char **myptr, size_t *mysize)
{
	char **newsize;
	size_t j;

	newsize = malloc(sizeof(char *) * ((*mysize) + 10));
	if (newsize == NULL)
	{
		free(myptr);
		return (NULL);
	}
	for (j = 0; j < (*mysize); j++)
	{
		newsize[j] = myptr[j];
	}
	*mysize += 10;
	free(myptr);
	return (newsize);
}

