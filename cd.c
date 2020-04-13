#include "shell.h"

/**
  * _cd - change directory
  * @argv: argument vector
  * @env: environment linked list
  */
void _cd(char **argv, env_list_t **env)
{
	char buf[BUFSIZ]; /* BUFSIZ is predefined~8k */
	char *cp;
	char *home = _getenv_list_value("HOME", env);
	char *OLDPWD[4] = {"", "OLDPWD", buf, NULL};
	char *PWD[4] = {"", "PWD", buf, NULL};

	cp = getcwd(buf, sizeof(buf));
	printf("Current dir: %s\n", buf);

	printf("Changing to %s\n", argv[1]);

	if (_strcmp(argv[1], "~"))
		chdir(argv[1]);
	else
		chdir(home);

	_setenv_list(OLDPWD, env);

	cp = getcwd(buf, sizeof(buf));
	printf("Current dir is now: %s, %lu bytes\n", buf, strlen(buf));
	_setenv_list(PWD, env);
}
