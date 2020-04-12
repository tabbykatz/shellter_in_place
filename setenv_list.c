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
	env_list_t *head = NULL;
	env_list_t *new_env = NULL;
	extern char **environ;
	char *token;
	int var_count = 0;

	printf("=initenv_list\n");

	for (var_count = 0; environ[var_count]; var_count++)
	{
		new_env = malloc(sizeof(env_list_t));
		if (head)
			head->next = new_env;
		token = strdup(strtok(environ[var_count], "="));
		new_env->NAME = token;
		token = strdup(strtok(NULL, " "));
		new_env->VALUE = token;
		new_env->next = NULL;
		head = new_env;
		if (var_count == 0)
			*env = head;
	}

	return env;
}

void printenv_list(env_list_t **env)
{
	env_list_t *i = *env;

	printf("=printenv_list\n");
	while (i)
	{
		printf("%s", i->NAME);
		printf("=");
		printf("%s\n", i->VALUE);
		i = i->next;
	}
}

int main(void)
{
	env_list_t **env = _initenv_list();
	
	printf("%s\n", (*env)->NAME);

	printenv_list(env);
	return (0);
}
