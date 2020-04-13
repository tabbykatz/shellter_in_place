#include "shell.h"

void built_in_handler(char **argv, env_list_t **env, int i)
{
	switch (i)
	{
		case 0:
			_cd(argv, env);
			break;
		case 1:
			_setenv_list(argv, env);
			break;
		case 2:
			_unsetenv_list(argv, env);
			break;
		case 3:
			printenv_list(env);
			break;
	}
}

int cmd_handler(char **argv, env_list_t **env)
{
	char *built_ins[] = {"cd", "setenv", "unsetenv", "env", NULL};
	int i, status;
	struct stat st;
	char *path_to_file;
	pid_t child_pid;
	char **str_env = _get_str_env(env);

	/* if it's a buitin */
	for (i = 0; built_ins[i]; i++)
	{
		if (!strcmp(built_ins[i], argv[0]))
		{
			built_in_handler(argv, env, i);
			return (1);
		}
	}

	path_to_file = whitcher(argv[0], env);
	
	/* if it's a full-path cmd */
	/* else if it can be found in the PATH */
	/* Else it must not be a cmd */
	if (stat(argv[0], &st) == 0)
		path_to_file = argv[0];
	else if (strcmp(path_to_file, _getenv_list_value("PATH", env)))
	{
		path_to_file = strcat(whitcher(argv[0], env), "/");
		path_to_file = strcat(path_to_file, argv[0]);
	}
	else
	{
		printf("Sorry, that's not a thing\n");
		return (0);
	}
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (0);
	}
	if (child_pid == 0)
	{
		if (execve(path_to_file, argv, str_env) == -1)
			perror("Error:");
		exit(0);
	}
	wait(&status);
/*
	free(path_to_file);
*/
	return (1);
}
