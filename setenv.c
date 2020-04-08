#include "protos.h"

int main(void)
{
	extern char **environ;
	char **new_env;
	char *new_entry = strdup("height=6ft");
	int var_count = 0;

	for (var_count = 0; environ[var_count]; var_count++)
	{}

	new_env = malloc(sizeof(char *) * (var_count + 2));
	for (var_count = 0; environ[var_count]; var_count++)
	{
		new_env[var_count] = environ[var_count];
	}
	new_env[var_count++] = new_entry;
	new_env[var_count] = NULL;

	environ = new_env;
	
	/*	
	for (var_count = 0; temp[var_count]; var_count++)
	{
		free(temp[var_count]);
	}
	free(temp);
	*/
	char *argv[] = {"/usr/bin/env", NULL};
	execve(argv[0], argv, environ);
	
	return (0);
}
