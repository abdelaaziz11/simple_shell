#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
* main - read and implement the functions
* @ac: argumant count
* @av: pointer array of argument vector
* @env: environment
* Return: 0 if success or 1 if Failure
*/
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int status;
	char *buffer = NULL, **argv, *command;
	size_t size_buf = 0;
	ssize_t number_char;
	pid_t pid;

	while (1)
	{
	printf("$ ");
	number_char = getline(&buffer, &size_buf, stdin);
	if (number_char == EOF)
		printf("\n"), exit(1);
	argv = str_split(buffer, " \t\n");
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
