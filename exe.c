#include "main.h"
/**
 * exec_File - executes the specified files
 * @command_line: execute file
 * @programName: av of main
 * Return: The status
*/
int exec_File(char *command_line, char *programName)
{
	char **arg = NULL, **env = environ, *pat;
	int num_arg, s = 0;
	pid_t pid;

	if (*command_line != '\0' && *command_line != '#')
	{
		command_line = find_com(command_line);
		num_arg = count_args(command_line);
		arg = create_buf(num_arg, command_line);
		pat = FullPath(arg[0]);
		if (pat != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(pat, arg, env);
				perror(arg[0]);
			}
			else if (pid > 0)
				waitpid(pid, &s, 0);
			else
				perror("fork");
		}
		else
		{
			write(STDERR_FILENO, programName, strlen(programName));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, arg[0], strlen(arg[0]));
			write(STDERR_FILENO, ": not found\n", 12);
		}
		(pat != arg[0]) ? free(pat) : (void)0;
		Custom_free(arg);
	}
	return (s);
}

/**
 * FullPath - provides the full path of a file
 * @file_name: the file to look for
 * Return: pointer to the path of the file
*/
char *FullPath(char *file_name)
{
	int i;
	char pat[BUFF_SIZE], *ptr_pat, **env = environ, *pats, *f_pats;

	if (access(file_name, F_OK) == 0)
		return (file_name);
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strn_cmp(env[i], "PATH=", 5) == 0)
		{
			pats = _str_dup(env[i] + 5);
			f_pats = strtok(pats, ":");
			for (; f_pats; f_pats = strtok(NULL, ":"))
			{
				ptr_pat = _str_cpy(pat, f_pats);
				ptr_pat = _str_cat(pat, "/");
				ptr_pat = _str_dup(_str_cat(pat, file_name));
				if (access(ptr_pat, X_OK) == 0)
				{
					free(pats);
					return (ptr_pat);
				}
				free(ptr_pat);
				f_pats = strtok(NULL, ":");
			}
			free(pats);
		}
	}
	return (NULL);
}

