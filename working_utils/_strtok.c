#include "protos.h"
/**
 * _strtok - tokenizes a string
 * @input: the string to tokenize
 * @delim: where to divide tokens (" ")
 * Return: pointer to token
 */

char *_strtok(char *input, char *delim)
{
	/* declarations */
	static char *begin;
	static char *prevNull;
	char *token = NULL;
	int i;

	/* assign begin, check input */
	if (input)
		begin = input;

	if (!begin)
		return (NULL);

	/* look to see where we are in the string, after first call */
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

	/* point to the beginning, look for delim, change to '\0' */
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
