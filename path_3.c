#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void path()
{
	char *path = getenv("PATH");

	if (path != NULL)
	{
		char *folder = strtok(path, ":");

		while (folder != NULL)
		{
			printf("I found a folder place: %s\n", folder);
			folder = strtok(NULL, ":");
		}
	}
	else
	{
		printf("There are no folder places here.\n");
	}
}

int main()
{
	path();
	return (0);
}
