#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _strtok - tokenizes a string
 * @input: the string to tokenize
 * @delim:there to divide tokens (" ")
 * Return: pointer to token
 */
char *_strtok(char *input, char delim)
{
	static char *start;
	static char *prevNull;
	char *ret = NULL;

	if (input)
		start = input;

	if (!start)
		return (NULL);

	if (*start == '\0')
	{
		if (start == prevNull)
		{
			start = NULL;
			return (NULL);
		}
		prevNull = start;
		return (start);
	}

	ret = start;
	while (*start)
	{
		if (*start == delim)
		{
			*start = '\0';
			prevNull = start;
			start++;
			return (ret);
		}
		start++;
	}
	prevNull = start;

	return (ret);
}
int main(void)
{
	char *string = "This is a string";
	char *stringDup = strdup(string);
	char *token = NULL;

	token = _strtok(stringDup, " ");
	while (token)
	{
		printf("%s\n", token);
		token = _strtok(NULL, " ");
	}
	return (0);
}
