#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024
#define PATH_MAX 1024

extern char **environ;

char *_getenv(const char *name);
char *get_cmd(char *command);
char **str_split(char *buffer, char *del);
int my_unsetenv(char **commandArgs);
int my_setenv(char **commandArgs);
/*int my_cd(char **commandArgs);*/
int executeMultipleCommands(char **commands, char **env);
/*int executeAlias(char **commandArgs);*/
/*int executeCommandWithExitStatus(char **argv, char **env);*/
void executeRedirectCommand(char **argv, char **env);
void executeCommand(char **argv, char **env);


#endif /* MAIN_H */
