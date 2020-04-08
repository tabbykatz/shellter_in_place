#include "protos.h"

int main(void)
{
	extern char **environ;
	char *new_entry = strdup("height=6ft");
	int var_count = 0;

	for (var_count = 0; environ[var_count]; var_count++)
	{}

	environ = realloc(environ, sizeof(char *) * (var_count + 2));
	environ[var_count++] = new_entry;
	environ[var_count] = NULL;

	char *argv[] = {"/usr/bin/env", NULL};
	execve(argv[0], argv, environ);
	
	return (0);
}
