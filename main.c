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
	int status;
	char *buffer = NULL, *command;
	size_t size_buf = 0;
	ssize_t number_char;
	pid_t pid;
	(void)argc;

	while (1)
	{
	write(1, "$ ", 2);
	number_char = getline(&buffer, &size_buf, stdin);
	if (number_char == EOF)
		printf("\n"), exit(1);
	argv = str_split(buffer, " \t\n");
	if (buffer[0] == '#')
		continue;
	if (strcmp(argv[0], "exit") == 0)
		exit(0);
	pid = fork();
	if (pid == 0)
	{
		command = get_cmd(argv[0]);
		if (command)
			execve(command, argv, env);
		else
			printf("Command doesn't found\n"), exit(0);
	}
	else
		wait(&status);
	}
	return (0);
}
