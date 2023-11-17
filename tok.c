#include "simple.h"

char **tok(char *line)
{
	char *token = NULL, *copy;
	char **cmd = NULL;
	int count = 0, i = 0;

	if (!line)
		return (NULL);
	copy = strdup(line);
	token = strtok(copy, " \t\n");
	if (token == NULL)
	{
		free(line), line = NULL;
		free(copy), copy = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}
	free(copy), copy = NULL;
	if (cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}
	cmd = malloc(sizeof(char *) * (count + 1));
	token = strtok(line, " \t\n");
        while (token)
        {
                cmd[i] = strdup(token);
                token = strtok(NULL, " \t\n");
        	i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
