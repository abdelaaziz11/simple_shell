#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
* my_unsetenv - Delete environment variable
* @commandArgs: command of arguments
* Return: 0 if success or -1 if failure
*/

int my_unsetenv(char **commandArgs)
{
	if (commandArgs[1] == NULL || commandArgs[2] != NULL)
	{
	fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	if (unsetenv(commandArgs[1]) == -1)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}
