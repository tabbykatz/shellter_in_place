#include "shell.h"

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
			double_free(env);
			return (exit_status);
		}

		cmd_handler(argv, &env);
	}
	return (0);
}
