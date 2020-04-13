#include "shell.h"

/**
 * _strtok - tokenizes a string
 * @input: the string to tokenize
 * @delim: where to divide tokens (" ")
 * Return: pointer to token
 */
char *_strtok(char *input, char *delim)
{
	static char *begin;
	static char *prevNull;
	char *token = NULL;
	int i;

	if (input)
		begin = input;
	if (!begin)
		return (NULL);
	if (*begin == '\0')
	{
		if (begin == prevNull)
		{
			begin = NULL;
			return (NULL);
		}
		prevNull = begin;
		return (begin);
	}
	token = begin;
	while (*begin)
	{
		for (i = 0; delim[i]; i++)
		{
			if (*begin == delim[i])
			{
				*begin = '\0';
				prevNull = begin;
				if (*(begin + 1) != '\0')
					begin++;
				return (token);
			}
		}
		begin++;
	}
	prevNull = begin;
	return (token);
}
