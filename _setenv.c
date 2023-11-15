#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
* _setenv - add environment variable or change environment variable
* @key: name of environment variable
* @value: value of environment variable
* @overwrite: overwrite and change environment variable
* Return: Always 0
*/
int _setenv(const char *key, const char *value, int overwrite)
{
	char *new_envar;
	int len = 0, i = 0;

	if (key == NULL || value == NULL)
		return (-1);
	if (getenv(key) != NULL && !overwrite)
	{
		fprintf(stderr, "%s\n", key);
		return (-1);
	}
	if (setenv(key, value, 1) != 0)
	{
		fprintf(stderr, "%s\n", key);
		return (-1);
	}
	while (environ[i])
	{
		len = strlen(key);
		if (strncmp(environ[i], key, len) == 0)
		{
			if (overwrite)
			{
				new_envar = malloc(strlen(key) + strlen(value) + 2);
				new_envar = strdup(key);
				strcat(new_envar, "=");
				strcat(new_envar, value);
				environ[i] = new_envar;
				return (0);
			}
		}
		i++;
	}
	new_envar = malloc(strlen(key) + strlen(value) + 2);
	new_envar = strdup(key);
	strcat(new_envar, "=");
	strcat(new_envar, value);
	environ[i] = new_envar;
	environ[i + 1] = NULL;
	return (0);
}
