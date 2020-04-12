#include "shell.h"

char **_get_str_env(env_list_t **env);

int main(void)
{
	env_list_t **env = _initenv_list();
	char *argv[4] = {"", "FARTS", "GOOD", NULL};
	char **str_env = _get_str_env(env);
	int i = 0;

	for (i = 0; str_env[i]; i++)
	{
		printf("%s\n", str_env[i]);
	}
	printf("success!\n");
/*
	printf("%s\n", (*env)->name);

	printenv_list(env);
	
	printf("\nPATH: %s\n", _getenv_list_value("PATH", env));

	_setenv_list(argv, env);

	printenv_list(env);
	
	_unsetenv_list(argv, env);

	printenv_list(env);
*/
	free_env_list(env);
	return (0);
}
