#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

char **tokenize(char *tok_str);

char *whitcher(char *cmd)
{
	char *PATH = getenv("PATH");
	char **tokens;
	int i;

	tokens = tokenize(strdup(PATH));

	for (i = 0; tokens[i]; i++)
	{
		if (!strcmp(cmd, tokens[i]))
			return (tokens[i]);
		printf("%s\n", tokens[i]);
	}

	printf("FULL PATH: %s\n", PATH);
}

char **tokenize(char *tok_str, char *delim)
{
	char *token = NULL;
	char **tokens;
	char *temp = NULL;
	size_t count = 0;

	temp = strdup(tok_str);
	if (!temp)
		return (NULL);
	token = strtok(temp, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(temp);
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);

	token = strtok(tok_str, delim);
	for (count = 0; token; count++)
	{
		printf("%zu: %s\n", count, token);
		tokens[count] = token;
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;

	return tokens;
}
