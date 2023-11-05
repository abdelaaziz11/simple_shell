#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * check_command - function that checks for the path
 * @command: a command
 *
 * Return: result
 */

void check_command(char *command)
{
	if (access(command, F_OK) == 0)
		printf("%s: FOUND\n", command);
	else
		printf("%s: NOT FOUND\n", command);
}

/**
 * main - the main function
 *
 * Return: return zero
 */

int main()
{
	char *buffer = NULL;
	size_t buffer_size;
	ssize_t chars;
	char *token;
	(void)chars;

	while (1)
	{
		write(1, "$ ", 2);
		chars = getline(&buffer, &buffer_size, stdin);
		token = strtok(buffer, " \t\n");
		if (strcmp(token, "_which") == 0)
		{
			token = strtok(NULL, " \t\n");
			while (token)
			{
				check_command(token);
				token = strtok(NULL, " \t\n");
			}
		}
		else
			printf("Command doen't existed\n");
	}
	return (0);
}
