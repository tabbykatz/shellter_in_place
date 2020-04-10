#include "protos.h"

void cmd_handler(char **argv, char ***env)
{
	char *built_ins[] = {"cd", "setenv", "unsetenv", "env", NULL};
	int i;
	struct stat st;
	char *path_to_file;

	/* if it's a buitin */
	for (i = 0; built_ins[i]; i++)
	{
		if (!strcmp(built_ins[i], argv[0]))
		{
			printf("it's a built-in!");
			return;
		}
		/* fire built_in fnc */
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

	if (execve(path_to_file, argv, *env) == -1)
		perror("Error:");
}
