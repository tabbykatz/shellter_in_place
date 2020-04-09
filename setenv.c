#include "protos.h"

char **_initenv(void)
{
	char **new_env;
	extern char **environ;
	int var_count = 0;

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

void _setenv(char *entry, char ***env)
{
	char **new_env;
	int var_count = 0;
	
	printf("setenv\n\n");

	for (var_count = 0; (*env)[var_count]; var_count++)
	{
		printf("%d: %s\n", var_count, (*env)[var_count]);
	}

	new_env = malloc(sizeof(char *) * (var_count + 2));
	for (var_count = 0; (*env)[var_count]; var_count++)
	{
		new_env[var_count] = (*env)[var_count];
	}
	new_env[var_count++] = entry;
	new_env[var_count] = NULL;

	*env = new_env;
}

void _unsetenv(char *entry, char ***env)
{
	char **new_env;
	int var_count;
	int i;

	printf("unsetenv\n\n");

	for (var_count = 0; (*env)[var_count]; var_count++)
	{
		printf("%d: %s\n", var_count, (*env)[var_count]);
	}

	new_env = malloc(sizeof(char *) * var_count);

	for (var_count = 0, i = 0; (*env)[var_count]; var_count++)
	{
		if (strcmp(entry, (*env)[var_count]))
		{
			new_env[i] = (*env)[var_count];
			i++;
		}
	}
	new_env[var_count - 1] = NULL;
	
	*env = new_env;
}

int main(void)
{
	char **env;
	char *new_entry = strdup("ENVIRO=TOXIC");
	int i;
	pid_t child_pid;
	int status;

	env = _initenv();
	
	_setenv(new_entry, &env);
	
	char *argv[] = {"/usr/bin/env", NULL};
	child_pid = fork();
	if (child_pid == 0)
	{
		execve(argv[0], argv, env);
		return (0);
	}
	wait(&status);
	
	printf("unset\n");
	_unsetenv(new_entry, &env);

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(argv[0], argv, env);
		return (0);
	}
	wait(&status);
	return (0);
}
