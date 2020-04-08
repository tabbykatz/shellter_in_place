#include <stdio.h>

int main(void)
{
	extern char **environ;
	
	while (*environ)
	{
		printf("%s\n", *environ++);
	}
	return 0;
}
