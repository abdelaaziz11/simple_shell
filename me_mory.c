#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}
