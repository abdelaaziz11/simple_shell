#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Fork plus wait plus execve
 *
 * Return: 0 if success or 1 if failure
 */
int main()
{
	int i, status;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL))
			{
				perror("execve");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
