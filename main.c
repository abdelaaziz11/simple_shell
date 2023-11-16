#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
* main - read and implement the functions
* @argc: argumant count
* @argv: pointer array of argument vector
* @env: environment
* Return: 0 if success or 1 if Failure
*/
int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, **commandArgs;
	size_t size_buffer;
	ssize_t number_char;
	(void)argc;
	(void)argv;

	while (1)
	{
		write(1, "$ ", 2);
		number_char = getline(&buffer, &size_buffer, stdin);
		if (number_char == EOF)
		{
			printf("\n");
			free(buffer), exit(EXIT_FAILURE);
		}
		commandArgs = str_split(buffer, " \t\n");
		if (buffer[0] == '#' || commandArgs[0] == NULL)
		{
			free(commandArgs);
			continue;
		}
		if (strcmp(commandArgs[0], "exit") == 0)
		{
			free(buffer);
			free(commandArgs), exit(EXIT_SUCCESS);
		}
		if (strstr(buffer, "&&") != NULL || strstr(buffer, "||") != NULL)
		{
			commandArgs = str_split(buffer, "&|\n");
			executeMultipleCommands(commandArgs, env);
			free(commandArgs);
		}
		else if (strchr(buffer, '>') != NULL)
			executeRedirectCommand(commandArgs, env);
		else
			executeCommand(commandArgs, env);
		free(commandArgs);
	}
	return (0);
}
