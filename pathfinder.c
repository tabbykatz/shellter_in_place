#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

char **tokenize(char *PATH);

int main(int ac, char **av)
{
	char *PATH = getenv("PATH");
	char **tokens;
	int i;

	if (ac < 2)
	{
		printf("Usage: ./a.out FILENAME DIRECTORY\n");
		return (0);
	}
	if (directory)
		closedir("av[ac - 1]");

	tokens = tokenize(strdup(PATH));

	for (i = 0; tokens[i]; i++)
	{
		printf("%s\n", tokens[i]);
	}

	printf("FULL PATH: %s\n", PATH);




	for (i = 0; tokens[i]; i++)
	{
		if (!stat(tokens[i]))
		{
			printf("FOUND\n");
			break;
		}
	}
	if (tokens[i] == NULL)
		printf("NOT FOUND\n");
	
	free(tokens[0]);
}

char **tokenize(char *PATH)
{
	char *token = NULL;
	char **tokens;
	char *temp = NULL;
	size_t count = 0;

	temp = strdup(PATH);
	if (!temp)
		return (NULL);
	token = strtok(temp, ":");
	while (token)
	{
		count++;
		token = strtok(NULL, ":");
	}
	free(temp);
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);

	token = strtok(PATH, ":");
	for (count = 0; token; count++)
	{
		printf("%zu: %s\n", count, token);
		tokens[count] = token;
		token = strtok(NULL, ":");
	}
	tokens[count] = NULL;

	return tokens;
}
