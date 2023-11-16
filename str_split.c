#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
* str_split - Spliting the strings
* @buffer: string
* @del: delimeter
* Return: number of characters
*/

char **str_split(char *buffer, char *del)
{
	char *token, **all_tokens;
	int i = 0;

	token = strtok(buffer, del);
	all_tokens = malloc(sizeof(char *) * 1024);
	if (all_tokens == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	while (token)
	{
		all_tokens[i] = strdup(token);
		if (all_tokens[i] == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, del);
		i++;
	}
	all_tokens[i] = NULL;
	return (all_tokens);
}
