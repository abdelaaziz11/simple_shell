#include "simple.h"

void free(char **arr)
{
	int i;

	if (!arr)
		return (0);
	for (i = 0; arr[i]; i++)
		free(arr[i]), arr[i] = NULL;
	free(arr), arr = NULL;

}
