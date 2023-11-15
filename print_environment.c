#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_environment - That prints environment
 * Return: nothing
 */

void print_environment()
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
