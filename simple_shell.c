#include "protos.h"

int main(void)
{
	int status;
	pid_t child_pid;
	char *line = NULL, *temp_line;
	char *token, *temp_token;
	size_t line_size = 0;
	ssize_t getline_size;
	char **argv;
	size_t ac;
	int i;

	printf("ShiP$ ");
	getline_size = getline(&line, &line_size, stdin);
	line[getline_size - 1] = '\0';
	printf("line_size: %zu\n", getline_size);

	argv = get_tokens(line, " ");

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error:");
		return (0);
	}

	wait(&status);
	free(line);
	free(argv);

	return (0);
}
