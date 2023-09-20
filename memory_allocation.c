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
	size_t new_size = (*mysize) * 2 + 10;
	size_t j;

	char **new_ptr = malloc(sizeof(char *) * new_size);

	if (new_ptr == NULL)
	{
		free(myptr);
		return (NULL);
	}

	for (j = 0; j < (*mysize); j++)
	{
		new_ptr[j] = myptr[j];
	}

	for (j = (*mysize); j < new_size; j++)
	{
		new_ptr[j] = NULL;
	}

	*mysize = new_size;

	free(myptr);

	return (new_ptr);
}

