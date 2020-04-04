#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int is_del(char c, const char *del)
{
	while (*del && del)
	{
		if (c == *del)
		{
			return (1);
		}
		++del;
	}
	return (0);
}
/**
*
*
*
*
*
*/
int _strlen(char *str)
{
	int i;

	for (i = 0; str; i++)
	{}
	return (i);
}
/**
 * _strtok - creates tokens from a string
 * @input: input string from getline
 * @del: delimiter = " ";.
 *
 * Return: token from a string in an array.
 */
char *_strtok(char *input, const char *del)
{
	static unsigned int ct;
	static char *strtoke;
	char *token = NULL;
	int chk_spc = 0;

	if (input)
	{
		strtoke = input;
		for (ct = 0; strtoke[ct]; ct++)
		{
			if (is_del(strtoke[ct], del))
				strtoke[ct] = '\0';
		}
	}

	if (strtoke == NULL || *strtoke == '\0')
		return (NULL);

	token = strtoke;

	ct = _strlen(strtoke);

	if (strtoke[ct] == '\0' && _strlen(strtoke) > 0)
		chk_spc = 1;
	strtoke = strtoke + _strlen(strtoke) + chk_spc;
	return (token);
}
