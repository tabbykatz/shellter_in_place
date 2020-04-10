#include "protos.h"

int main(void)
{
	int status, exit_status = 0;
	pid_t child_pid;
	size_t line_size = 0;
	ssize_t getline_size;
	char **argv, **env, *path_to_file, *line = NULL;
	struct stat st;

	env = _initenv();
	while (1)
	{
		printf("ShiP$ ");
		getline_size = getline(&line, &line_size, stdin);
		line[getline_size - 1] = '\0';
		printf("line_size: %li\n", getline_size);

		rem_comments(line);
		argv = get_tokens(line, " ");

		if (!_strcmp(argv[0], "exit") || getline_size == -1)
		{
			if (argv[1])
				exit_status = _atoi(argv[1]);
			free(line);
			free(env);
			return (exit_status);
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
		}
		if (child_pid == 0)
		{
			cmd_handler(argv, &env);
		}
		wait(&status);
	}
	return (0);
}
