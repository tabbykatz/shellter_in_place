#include "shell.h"

char **_initenv(void)
{
	char **new_env;
	extern char **environ;
	int var_count = 0;

	printf("=initenv\n");
	for (var_count = 0; environ[var_count]; var_count++)
	{}

	new_env = malloc(sizeof(char *) * (var_count + 1));

	for (var_count = 0; environ[var_count]; var_count++)
	{
		new_env[var_count] = strdup(environ[var_count]);
	}
	new_env[var_count] = NULL;

	return new_env;
}

void _setenv(char **argv, char ***env)
{
	char **new_env;
	int var_count = 0;
	size_t entry_size = _strlen(argv[1]) + _strlen(argv[2]) + 2;
	char *new_entry = malloc(sizeof(char) * entry_size);

	printf("=setenv\n\n");

	new_entry = _strcpy(new_entry, argv[1]);
	new_entry = _strcat(new_entry, "=");
	new_entry = _strcat(new_entry, argv[2]);

	for (var_count = 0; (*env)[var_count]; var_count++)
	{}

	new_env = malloc(sizeof(char *) * (var_count + 2));
	for (var_count = 0; (*env)[var_count]; var_count++)
	{
		new_env[var_count] = (*env)[var_count];
	}
	new_env[var_count++] = new_entry;
	new_env[var_count] = NULL;

	*env = new_env;
}

void _unsetenv(char *entry, char ***env)
{
	char **new_env;
	int var_count;
	int i;
	int success = 0;

	printf("=unsetenv\n\n");

	for (var_count = 0; (*env)[var_count]; var_count++)
	{
		printf("%d: %s\n", var_count, (*env)[var_count]);
	}

	new_env = malloc(sizeof(char *) * var_count);

	for (var_count = 0, i = 0; (*env)[var_count]; var_count++)
	{
		if (strncmp(entry, (*env)[var_count], _strlen(entry)))
		{
			new_env[i] = (*env)[var_count];
			i++;
		}
		else
			success = 1;
	}
	if (success)
		new_env[var_count - 1] = NULL;
	
	*env = new_env;
}

char *_getenv(char *entry, char ***env)
{
	int var_count;
	char *val;
	char *env_var = strdup(entry);

	printf("=getenv\n");
	for (var_count = 0; (*env)[var_count]; var_count++)
	{
		if (!strncmp(env_var, (*env)[var_count], strlen(env_var)))
		{
			env_var = strchr((*env)[var_count], '=') + 1;
			return env_var;
		}
	}
	free(env_var);
	return NULL;
}

void _printenv(char ***env)
{
	int i;

	for (i = 0; (*env)[i]; i++)
	{
		printf("%s\n", (*env)[i]);
	}
}
