#include "shell.h"

/* this function tests the _cd.c file */
/* compile with gcc working_utils/*.c (plus cd.c if not in dir) */
int main(void)
{
	env_list_t **env = _initenv_list();
	char *argv[3] = {"cd", "..", NULL};
	
	_cd(argv, env);

	printenv_list(env);
	free_env_list(env);

	return 0;
}
