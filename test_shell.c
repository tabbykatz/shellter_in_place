#include "protos.h"

int main(void)
{
	int status;
	pid_t child_pid;
	size_t line_size = 0;
	ssize_t getline_size;
	char **argv, **env, *path_to_file, *line = NULL;
	struct stat st;

	env = _initenv();

	printf("ShiP$ ");
	getline_size = getline(&line, &line_size, stdin);
	line[getline_size - 1] = '\0';
	printf("line_size: %li\n", getline_size);

	/* TODO: remove comments */
	argv = get_tokens(line, " ");

	if (stat(argv[0], &st) == 0)
		path_to_file = argv[0];
	else
	{
		path_to_file = strcat(whitcher(argv[0]), "/");
		path_to_file = strcat(path_to_file, argv[0]);
	}

	printf("path_to_file: %s\n", path_to_file);
	
	/* TODO: handle execve in a fnc */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}
	if (child_pid == 0)
	{
		if (execve(path_to_file, argv, env) == -1)
			perror("Error:");
		return (0);
	}

	wait(&status);

	free(line);
	free(argv);

	return (0);
}
