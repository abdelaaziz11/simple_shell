#include "main.h"
/**
* executeCommandWithExitStatus - execute Command With Exit Status
* @argv: array of argument
* @env: environment
* Return: 0 or -1
*/
int executeCommandWithExitStatus(char **argv, char **env)
{
	char *command;
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		command = get_cmd(argv[0]);
		if (command)
		{

			if (execve(command, argv, env) == -1)
			{
				fprintf(stderr, "Execution failed\n");
				perror("execve");
				status = EXIT_FAILURE;
			}
			else
				status = EXIT_SUCCESS;
			free(command);
			exit(status);
		}
		else
			fprintf(stderr, "Command not found\n"), exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("Fork failed");
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			char *exit_status_str = WEXITSTATUS(status) == EXIT_SUCCESS ? "0" : "1";
			char *setenv_args[] = {"setenv", "?", NULL, NULL};

			setenv_args[2] = exit_status_str;
			if (my_setenv(setenv_args) == -1)
				return (-1);
		}
	}
	return (0);
}
