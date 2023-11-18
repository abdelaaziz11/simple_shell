#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * executeCommand - That execute commands
 * @argv: array argument
 * @env: environment variable
 * Return: nothing
 */
void executeCommand(char **argv, char **env)
{
	pid_t pid = fork();
	int i;
	char *var_name, *var_value, *command, pid_str[20];

	if (pid == 0)
	{
		command = get_cmd(argv[0]);
		if (command)
		{
			for (i = 0; argv[i] != NULL; i++)
			{
				if (argv[i][0] == '$' && argv[i][1] != '\0')
				{
					var_name = &argv[i][1];
					var_value = _getenv(var_name);
					if (var_value != NULL)
						argv[i] = var_value;
				}
				if (strcmp(argv[i], "$$") == 0)
				{
					snprintf(pid_str, sizeof(pid_str), "%d", getpid());
					argv[i] = strdup(pid_str);
				}
			}

			if (execve(command, argv, env) == -1)
			{
				fprintf(stderr, "Execution failed\n");
				perror("execve");
			}
			free(command), exit(EXIT_FAILURE);
		}
		else
			fprintf(stderr, "Command not found\n"), exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("Fork failed");
	else
		wait(NULL);
}
