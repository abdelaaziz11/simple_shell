#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - getline functoin
 * @ac: arg
 * @av: arg string
 * Return: number of arg
 */

int main(int ac, char **av)
{
	(void)av;
	(void)ac;
    
	char *buffer;
	size_t size_buffer = 0;
	int n_char = 0;

	write(1, "$ ", 2);
	n_char = getline(&buffer, &size_buffer, stdin);
	if (!n_char)
	perror("getline");
	
	printf("%s", buffer);
	return (0);
}
