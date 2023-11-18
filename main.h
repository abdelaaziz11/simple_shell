#ifndef MAIN_H
#define MAIN_H

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1024

extern char **environ;

int _str_len(char *str);
char *_str_dup(char *str);
char *_str_cat(char *dest, char *src);
char *_str_cpy(char *dest, char *src);
int _strn_cmp(char *str1, char *str2, int n);

char *FullPath(char *file_name);

void Custom_free(char **args);
char **create_buf(int num_args, char *command);

char *Trim_spaces(char *previous_line);
int exec_File(char *command_line, char *programName);
int count_args(char *line);
char *find_com(char *command_line);

int getbuilt_in(char *str);
int built_in(char *command, char *free_line, int proces_stat);
void print_env(void);

#endif /* MAIN_H */

