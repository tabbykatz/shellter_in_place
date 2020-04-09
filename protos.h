#ifndef PROTOS_H
#define PROTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>

/* getline */
int _getline(char **lineptr, size_t *n, FILE *stream);

/* memory helpers */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* string helpers */
int _atoi(char *s);
int _strlen(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strtok(char *input, char *delim);
char **get_tokens(char *str_tok, char *delim);
int isin_dir(char *term, char *dir);
char *whitcher(char *cmd);

#endif /* PROTOS */
