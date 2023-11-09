#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
* _getenv - get the environment variable and the PATH of variable
* @name: name of the environment variable
* Return: string token or NULL if Failure
*/

char *_getenv(const char *name)
{
	extern char **environ;
	char *token;
	int i = 0;

	while (environ[i])
	{
		token =  strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);
}
