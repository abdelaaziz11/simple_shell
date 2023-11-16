#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
* my_setenv - add environment variable or change environment variable
* @commandArgs: command o arguments
* Return: Always 0 or -1
*/
int my_setenv(char **commandArgs)
{
	int overwrite;

	if (!commandArgs[1] || !commandArgs[2] || commandArgs[3] != NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	overwrite = 1;
	if (setenv(commandArgs[1], commandArgs[2], overwrite) == -1)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}
