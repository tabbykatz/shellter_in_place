#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid;
	int i = 0;
	int status;
	char *argv[] = {"/bin/ls", "-al", "/tmp", NULL}; 

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
			return (0);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
