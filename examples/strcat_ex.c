#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/* this fnc is going to tell me what I'm doing wrong */

int main(int ac, char **av)
{
	char *foo = strdup(av[1]);

	foo = strcat(foo, "=");
	foo = strcat(foo, av[2]);

	printf("%s\n", foo);
	free(foo);
	return (0);
}
