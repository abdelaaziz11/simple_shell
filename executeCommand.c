#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * executeCommand - That execute commands
 * @av: array argument
 * @env: environment variable
 * Return: nothing
 */
void executeCommand(char **av, char **env)
{
	pid_t pid = fork();
	char *command;

	if (pid == 0)
	{
		command = get_cmd(av[0]);
		if (command)
		{
		execve(command, av, env);
		perror("Execution failed");
		exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stderr, "Command not found\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		wait(NULL);
	}
}
