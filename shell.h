#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_prompt(void);
char **_separaArgs(char *);
void _exec(char **, char **, char av[], int);
char *_strtok(char *str, char *del);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _builtin(char **cmd, char **);
void hsh_cd(char **cmd, char **env);
void hsh_env(char **env);
char *get_env_var(char *variable, char **env);
char *get_cmd_path(char *varvalue, char *command);
void ctrc(int i);
void exitp(char *buffer);
void freedp(char **);
int msg(char av[], int count, char **args, int n);
#endif
