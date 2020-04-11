#include "shell.h"

void built_in_handler(char **argv, char ***env, int i)
{
	switch (i)
	{
		case 0:
			printf("cd\n");
			break;
		case 1:
			_setenv(argv, env);
			break;
		case 2:
			_unsetenv(argv[1], env);
			break;
		case 3:
			_printenv(env);
			break;
	}
}

void cmd_handler(char **argv, char ***env)
{
	char *built_ins[] = {"cd", "setenv", "unsetenv", "env", NULL};
	int i, status;
	struct stat st;
	char *path_to_file;
	pid_t child_pid;

	/* if it's a buitin */
	for (i = 0; built_ins[i]; i++)
	{
		if (!strcmp(built_ins[i], argv[0]))
		{
			built_in_handler(argv, env, i);
			return;
		}
	}

	path_to_file = whitcher(argv[0], env);
	
	/* if it's a full-path cmd */
	/* else if it can be found in the PATH */
	/* Else it must not be a cmd */
	if (stat(argv[0], &st) == 0)
		path_to_file = argv[0];
	else if (strcmp(path_to_file, _getenv("PATH", env)))
	{
		path_to_file = strcat(whitcher(argv[0], env), "/");
		path_to_file = strcat(path_to_file, argv[0]);
	}
	else
	{
		printf("Sorry, that's not a thing\n");
		return;
	}
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(path_to_file, argv, *env) == -1)
			perror("Error:");
		exit(0);
	}
	wait(&status);
/*
	free(path_to_file);
*/
	return;
}
