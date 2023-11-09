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
	char *token;
	int i = 0;

	while (environ[i])
	{
<<<<<<< HEAD
		char *env_copy = strdup(environ[i]);
		key = strtok(env_copy, "=");
		if (strcmp(key, name) == 0)
		return (strtok(NULL, "="));
		free(env_copy);
=======
		token =  strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
			return (strtok(NULL, "="));
>>>>>>> d7c8a0729e037d5db3e6f71e8805fb21fae97d23
		i++;
	}
	return (NULL);
}
<<<<<<< HEAD

int main()
{
	printf("%s\n", _getenv("ROOT"));
	return (0);
}
=======
>>>>>>> d7c8a0729e037d5db3e6f71e8805fb21fae97d23
