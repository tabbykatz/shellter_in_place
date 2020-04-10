#include "protos.h"

/* this function tests the cmd_handler() fnc */
/* compile it with all files in working_ults/ */
int main(void)
{
	char *argv[] = {"cd", NULL};
	char **env = _initenv();

	cmd_handler(argv, &env);
	return (0);
}
