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
	char *path_to_file;
	int i;

	printf("ShiP$ ");
	getline_size = getline(&line, &line_size, stdin);
	line[getline_size - 1] = '\0';
	printf("line_size: %zu\n", getline_size);

	argv = get_tokens(line, " ");

	if (stat(argv[0]) == 0)
		path_to_file = argv[0];
	else
	{
		path_to_file = strcat(whitcher(argv[0]), "/");
		path_to_file = strcat(path_to_file, argv[0]);
	}

	printf("path_to_file: %s\n", path_to_file);
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}
	if (child_pid == 0)
	{
		if (execve(path_to_file, argv, NULL) == -1)
			perror("Error:");
		return (0);
	}

	wait(&status);
	free(line);
	free(argv);

	return (0);
}
