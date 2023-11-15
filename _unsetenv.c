#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
* _unsetenv - Delete environment variable
* @key: name of environment variable
* Return: 0 if success or -1 if failure
*/

int _unsetenv(const char *key)
{
	int i = 0, len = 0;

	if (!key)
		return (-1);
	while (environ[i])
	{
		len = strlen(key);
		if (strncmp(environ[i], key, len) == 0)
		{
		free(environ[i]);
			return (0);
		}
		i++;
	}
	free(environ[i]);
	return (0);
}
