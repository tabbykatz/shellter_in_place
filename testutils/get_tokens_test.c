#include "protos.h"
#include <stdio.h>
#include <stdlib.h>
/* This function tests get_tokens.c file */


int main(void)
{
	char *PATH = getenv("PATH");
	char **tokens = get_tokens(PATH, ":");
	int i;

	for (i = 0; tokens[i]; i++)
	{
		printf("%d: %s\n", i, tokens[i]);
	}

	PATH = "/bin/ls -la /tmp";
	/*
	tokens = get_tokens(PATH, " ");
	for (i = 0; tokens[i]; i++)
	{
		printf("%d: %s\n", i, tokens[i]);
	}
	*/
	return (0);
}
