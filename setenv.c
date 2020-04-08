#include "protos.h"

void _setenv(char *entry, char ***env)
{
	char **new_env;
	int var_count = 0;

	for (var_count = 0; *env[var_count]; var_count++)
	{}

	new_env = malloc(sizeof(char *) * (var_count + 2));
	for (var_count = 0; *env[var_count]; var_count++)
	{
		new_env[var_count] = strdup(*env[var_count]);
	}
	new_env[var_count++] = entry;
	new_env[var_count] = NULL;

	*env = new_env;
}

/*
char **_initenv()
{
	char **new_env;
	extern char **environ;
	int var_count = 0;

	for (var_count = 0; environ[var_count]; var_count++)
	{}

	new_env = malloc(sizeof(char *) * var_count);
	for (var_count = 0; environ[var_count]; var_count++)
	{
		new_env[var_count] = strdup(environ[var_count]);
	}

	return new_env;
}
*/
int main(void)
{
	extern char**environ;
	char **env;
	char *new_entry = strdup("ENVIRO=TOXIC");
	int i;

	env = environ;

	_setenv(new_entry, &env);
	
	char *argv[] = {"/usr/bin/env", NULL};
	execve(argv[0], argv, environ);
	
	return (0);
}
