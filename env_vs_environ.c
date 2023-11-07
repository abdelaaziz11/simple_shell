#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char *arg[], char *envp[])
{
	printf("The address of env: %p\n", envp);
	printf("The address of environ: %p\n", environ);
	if (envp == environ)
	{
		printf("env && environ have the same address.\n");
	}
	else
	{
		printf("env && environ have different addresses.\n");
	}
	return (0);
}
