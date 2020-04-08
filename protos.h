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

char **get_tokens(char *str_tok, char *delim);
int isin_dir(char *term, char *dir);
char *whitcher(char *cmd);

#endif /* PROTOS */
