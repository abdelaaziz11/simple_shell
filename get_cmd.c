#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
* get_cmd - get the command in the string
* @command: command of string
* Return: command or NULL if Failure
*/

char *get_cmd(char *command)
{
	struct stat st;
	char *Path = _getenv("PATH");
	char *command_full, *token;

	token = strtok(Path, ":");
	while (token)
	{
		command_full = malloc(strlen(command) + strlen(token) + 2);
		strcpy(command_full, token);
		strcat(command_full, "/");
		strcat(command_full, command);
		if (stat(command_full, &st) == 0)
			return (command_full);
		free(command_full);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
