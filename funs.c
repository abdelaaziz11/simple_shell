#include "main.h"
/**
 * built_in - Examines if the command is a built-in or not
 * @command: the command
 * @free_line: line to free
 * @proces_stat: the status of the last process
 * Return: 1 if failure, 0 if success
*/
int built_in(char *command, char *free_line, int proces_stat)
{
	int isbuilt_in;

	isbuilt_in = getbuilt_in(command);
	return ((isbuilt_in == 0) ? (free(free_line),
				exit(WEXITSTATUS(proces_stat)), 0) :
			(isbuilt_in == 1) ? (print_env(), 1) : 0);
}
/**
 * print_env - prints the environment variables
*/
void print_env(void)
{
	int j = 0;

	while (environ[j])
	{
		write(STDOUT_FILENO, environ[j], _str_len(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}

/**
 * find_com - examines comment the provided line
 * @command_line: the input
 * Return: the command line
*/
char *find_com(char *command_line)
{
	int i;

	if (_str_len(command_line) >= 2)
	{
		for (i = 1; command_line[i] != '\0'; i++)
		{
			(command_line[i] == '#' && command_line[i - 1] == ' ') ?
				(command_line[i - 1] = '\0', 0) :
						0;
		}
	}
	return (command_line);
}

