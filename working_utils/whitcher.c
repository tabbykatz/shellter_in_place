#include "protos.h"

char *whitcher(char *cmd)
{
	char *PATH = getenv("PATH");
	char **tokens;
	int i;

	tokens = get_tokens(strdup(PATH), ":");

	printf("=whitcher\n");
	for (i = 0; tokens[i]; i++)
	{
		printf("%s\n", tokens[i]);
		/* if cmd is in the directory passed by tokens[i] */
		/* then return the dir */
		if (isin_dir(cmd, tokens[i]))
		{
			printf("%s FOUND in %s\n", cmd, tokens[i]);
			return (tokens[i]);
		}
	}

	printf("FULL PATH: %s\n", PATH);
	return ("ERROR 404: FILE NOT FOUND");
}
