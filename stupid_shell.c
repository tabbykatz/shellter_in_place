#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *line_buf = NULL;
	char *temp = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;
	pid_t child_pid;
	int status;
	char **args;
	int argcount = 1;
	char *token;
	int i;
	extern char** environ;
		/* shell prompt and argument acception*/
		printf("ShiP$ ");
		line_size = getline(&line_buf, &line_buf_size, stdin);
		
		line_buf[line_size - 1] = '\0';

		/* malloc for the number of strings */
		temp = strdup(line_buf);
		token = strtok(temp, " ");
		while (token != NULL)
		{
			argcount++;
			token = strtok(NULL, " ");
		}

		args = malloc(argcount * sizeof(char *));

		/* set those strings into our array */
		argcount = 0;
		token = strtok(line_buf, " ");
		while (token != NULL)
		{
			args[argcount] = token;
			printf("%d : %s\n", argcount, token);
			argcount++;
			token = strtok(NULL, " ");
		}
		
		/* not used in this example */
		(void)ac;

		/* executes our command */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
				perror("Error:");
			return (0);
		}
		else
		{
			wait(&status);
		}
}
