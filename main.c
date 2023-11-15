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
	char *buffer = NULL;
	size_t size_buffer;
	ssize_t number_char;
	char **commandArgs;
	(void)argc;
	(void)argv;

	while (1)
	{
		write(1, "$ ", 2);
		number_char = getline(&buffer, &size_buffer, stdin);
		if (number_char == EOF)
		{
			printf("\n");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		commandArgs = str_split(buffer, " \t\n");
		if (buffer[0] == '#')
		{
			free(commandArgs);
			continue;
		}
		if (strcmp(commandArgs[0], "exit") == 0)
		{
			free(buffer);
			free(commandArgs);
			exit(EXIT_SUCCESS);
		}
		executeCommand(commandArgs, env);
		free(commandArgs);
	}
	free(buffer);
	return 0;
}

