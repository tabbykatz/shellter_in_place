#include "shell.h"

/**
  * get_tokens - tokenizes a string
  * @tok_str: str to be tokenized
  * @delim: char * of delimiters
  * Return: char **, argument vector to be used in execve or other
  */
char **get_tokens(char *tok_str, char *delim)
{
	char *token = NULL;
	char **tokens;
	char *temp = NULL;
	size_t count = 0;

	temp = _strdup(tok_str);
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
		tokens[count] = token;
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;

	return (tokens);
}
