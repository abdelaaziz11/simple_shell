#include "main.h"
/**
 * main - function main that entry point
 * @ac: number of arguments
 * @av: array of arguments
 * Return: always 0
*/
int main(int ac, char *av[])
{
	size_t length;
	int nrc;
	char *line = NULL, *com;
	int loop = 0, status = 0;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#khouda/byd$ ", 13);
		nrc = getline(&line, &length, stdin);
		if (nrc >= 0)
		{
			line[nrc - 1] = '\0';
			com = Trim_spaces(line);
			status = (!built_in(com, line, status)) ? exec_File(com, av[0]) : status;
			free(line);
			line = NULL;
		}
		else
		{
			free(line);
			break;
		}
		loop++;
	}
	return (0);
}

/**
 * Trim_spaces - ignores surrounded spaces
 * in the command line
 * @previous_line: command line
 * Return: command line after the
 * spaces are removed.
*/
char *Trim_spaces(char *previous_line)
{
	char *endline, *newline = previous_line;

	for (; *newline == ' '; newline++)
		;
	endline = newline + (_str_len(newline) - 1);
	for (; endline > newline && *endline == ' '; endline--)
		;
	*(endline + 1) = '\0';
	return (newline);
}
/**
 * create_buf - allocates memory
 * @num_args: number of arguments
 * @command: command line
 * Return: arguments
 */
char **create_buf(int num_args, char *command)
{
	char **arg, *delimiter = " ", *args_use;
	int i = 0;

	arg = malloc((num_args + 1) * sizeof(char *));
	if (!arg)
		return (NULL);
	args_use = strtok(command, delimiter);
	for (i = 0; args_use != NULL; i++)
	{
	arg[i] = _str_dup(args_use);
	args_use = strtok(NULL, delimiter);
	}
	arg[i] = NULL;
	return (arg);
}
/**
 * Custom_free - free all memory
 * @args: arguments
 */
void Custom_free(char **args)
{
	int i;

	if (args != NULL)
	{
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}
}

