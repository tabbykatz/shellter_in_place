#include "shell.h"

void _cd(char **argv, env_list_t **env)
{
	
}

int main(void)
{
	char buf[BUFSIZ]; // BUFSIZ is ~8k
	char *cp;
	char *home;
	env_list_t **env = _initenv_list();
	char *OLDPWD[4] = {"", "OLDPWD", buf, NULL};
	char *PWD[4] = {"", "PWD", buf, NULL};

	printf("BUFSIZ = %d\n", BUFSIZ);
	cp = getcwd(buf, sizeof(buf));
	printf("Current dir: %s\n", buf);

	printf("Changing to ..\n");
	home = _getenv_list_value("HOME", env);
	chdir(home);			/* `cd ..' */

	_setenv_list(OLDPWD, env);
	
	cp = getcwd(buf, sizeof(buf));
	printf("Current dir is now: %s, %zu bytes\n", buf, strlen(buf));

	_setenv_list(PWD, env);
	printenv_list(env);

	free_env_list(env);

	return 0;
}
