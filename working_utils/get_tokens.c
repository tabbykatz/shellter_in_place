#include "protos.h"

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

	token = strtok(tok_str, delim);
	printf("=get_tokens\n");
	for (count = 0; token; count++)
	{
		printf("%lu: %s, %d bytes\n", count, token, _strlen(token));
		tokens[count] = token;
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;
	free(token);

	return tokens;
}
