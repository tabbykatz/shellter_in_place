#include <stdio.h>

void printenv()
{
	extern char **environ;

	while (*environ)
	{
		printf("%s\n", *environ++);
	}
}
