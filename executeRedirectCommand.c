#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
/**
 * executeRedirectCommand - execute Redirect Command
 * @argv: pointer array of argument vector
 * @env: environment
 */
void executeRedirectCommand(char **argv, char **env)
{
	int fd;
	char *command;
	pid_t pid = fork();

		if (pid == 0)
		{
		fd = open("filename.txt", O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
		if (fd == -1)
		{
			perror("Error opening file for writing");
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		command = get_cmd(argv[0]);
		if (command)
		{
			if (execve(command, argv, env) == -1)
			{
				fprintf(stderr, "Execution failed\n");
				perror("execve");
			}
			free(command);
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stderr, "Command not found\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("Fork failed");
	else
		wait(NULL);
}
