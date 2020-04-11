#include "shell.h"

int main(void)
{
	char buf[BUFSIZ]; // BUFSIZ is ~8k
	char *cp;
	char **env = _initenv();

	printf("BUFSIZ = %d\n", BUFSIZ);
	cp = getcwd(buf, sizeof(buf));
	printf("Current dir: %s\n", buf);

	printf("Changing to ..\n");
	chdir("..");			/* `cd ..' */

	char *OLDPWD[4] = {"", "OLDPWD", buf, NULL};

	cp = getcwd(buf, sizeof(buf));
	printf("Current dir is now: %s, %zu bytes\n", buf, strlen(buf));
	char *PWD[4] = {"", "PWD", buf, NULL};
	/* unsets the old PWD */
	_unsetenv("PWD", &env);
	/* sets the new PWD */
	_setenv(PWD, &env);

	_unsetenv("OLDPWD", &env);
	_setenv(OLDPWD, &env);

	_printenv(&env);

	return 0;
}
