#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char *key;

	while (environ[i])
	{
		char *env_copy = strdup(environ[i]);
		key = strtok(env_copy, "=");
		if (strcmp(key, name) == 0)
		return (strtok(NULL, "="));
		free(env_copy);
		i++;
	}
	return (NULL);
}

int main()
{
	printf("%s\n", _getenv("ROOT"));
	return (0);
}
