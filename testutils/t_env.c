#include "protos.h"

/* this file tests _initenv, _setenv, _unsetenv */
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
