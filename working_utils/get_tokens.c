#include "protos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

char **get_tokens(char *tok_str, char *delim)
{
	char *token = NULL;
	char **tokens;
	char *temp = NULL;
	size_t count = 0;

	temp = _strdup(tok_str);
	if (!temp)
		return (NULL);
	token = _strtok(temp, delim);
	while (token)
	{
		count++;
		token = _strtok(NULL, delim);
	}
	free(temp);
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);

	token = _strtok(tok_str, delim);
	printf("=get_tokens\n");
	for (count = 0; token; count++)
	{
		printf("%zu: %s, %zu bytes\n", count, token, _strlen(token));
		tokens[count] = token;
		token = _strtok(NULL, delim);
	}
	tokens[count] = NULL;

	return tokens;
}
