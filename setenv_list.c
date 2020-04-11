#include "shell.h"

typedef struct env_list
{
	char *NAME;
	char *VALUE;
	struct env_list *next;
} env_list_t;

env_list_t **_initenv_list(void)
{
	env_list_t **env;
	env_list_t *new_env;
	extern char **environ;
	char *token;
	int var_count = 0;

	printf("=initenv_list\n");

	*env = new_env;

	for (var_count = 0; environ[var_count]; var_count++)
	{
		new_env = malloc(sizeof(env_list_t));
		token = strdup(strtok(environ[var_count], "="));
		new_env->NAME = token;
		token = strdup(strtok(NULL, " "));
		new_env->VALUE = token;
		new_env = new_env->next;
	}
	
	
	return env;
}

int main(void)
{
	env_list_t **env = _initenv_list();
}
