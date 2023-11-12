#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_getenv(const char *name);
char *get_cmd(char *command);
char **str_split(char *buffer, char *del);
int _setenv(const char *key, const char *value, int change_flag);
int _unsetenv(const char *key);

#endif /* MAIN_H */
