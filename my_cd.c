#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>

#define PATH_MAX 1024
/**
 * my_cd - definition after the my_unsetenv function
 * @commandArgs: command of arguments
 * Return: 0 if success or -1if failure
*/
int my_cd(char **commandArgs)
{
	char *dir = commandArgs[1];
	char cwd[PATH_MAX];

	if (dir == NULL || commandArgs[2] != NULL)
	{
		fprintf(stderr, "Usage: cd [DIRECTORY]\n");
		return (-1);
	}
	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (-1);
		}
	}
	if (chdir(dir) == -1)
	{
		perror("chdir");
		return (-1);
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	return (0);
}
