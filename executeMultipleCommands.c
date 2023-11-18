#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>
/**
* executeMultipleCommands - definition after the my_cd function
* @commands: all commands
* @env: evironment
* Return: always
*/
int executeMultipleCommands(char **commands, char **env)
{
	char **commandArgs;
	int i = 0;

	while (commands[i] != NULL)
	{
		commandArgs = str_split(commands[i], " \t\n");
		if (commandArgs[0] == NULL)
		{
			free(commandArgs);
			i++;
			continue;
		}

		if (strcmp(commandArgs[0], "exit") == 0)
		{
			free(commandArgs);
			free(commands);
			exit(EXIT_SUCCESS);
		}
		executeCommand(commandArgs, env);
		free(commandArgs);
		i++;
	}

	return (0);
}
