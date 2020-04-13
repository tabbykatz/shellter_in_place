#include "shell.h"

char *whitcher(char *cmd, env_list_t **env)
{
	char *PATH = _getenv_list_value("PATH", env);
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
	return (PATH);
}
