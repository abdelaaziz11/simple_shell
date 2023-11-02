#include <stdio.h>
#include <stdlib.h>
/**
 * main - main function
 * @ac: integer
 * @av: character
 *
 * Return: arguments
 */

int main(int ac, char **av)
{
	(void)ac;
	int i = 0;

	while (av[i] != 0)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
