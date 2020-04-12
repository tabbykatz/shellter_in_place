#include "shell.h"

env_list_t **_initenv_list(void)
{
	env_list_t **env = malloc(sizeof(env_list_t *));
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
		new_env->name = token;
		token = strdup(strtok(NULL, " "));
		new_env->value = token;
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
		printf("%s", i->name);
		printf("=");
		printf("%s\n", i->value);
		i = i->next;
	}
}

char *_getenv_list_value(char *name, env_list_t **env)
{
	env_list_t *i = *env;

	printf("=_getenv_list\n");
	while (i)
	{
		if (!strcmp(name, i->name))
		{
			return (i->value);
		}
		i = i->next;
	}
	return (NULL);
}

env_list_t *_getenv_list_node(char *name, env_list_t **env)
{
	env_list_t *i = *env;

	printf("=_getenv_list\n");
	while (i)
	{
		if (!strcmp(name, i->name))
		{
			return (i);
		}
		i = i->next;
	}
	return (NULL);
}

void _setenv_list(char **argv, env_list_t **env)
{
	env_list_t *a, *b;

	if (a = _getenv_list_node(argv[1], env))
	{
		free(a->value);
		a->value = strdup(argv[2]);
		return;
	}

	a = *env;
	while (a->next)
	{
		a = a->next;
	}
	b = malloc(sizeof(env_list_t));
	b->name = strdup(argv[1]);
	b->value = strdup(argv[2]);
	b->next = NULL;
	a->next = b;
	return;
}

void free_env_list_node(env_list_t *node)
{
	free(node->name);
	free(node->value);
	free(node);
}

void _unsetenv_list(char **argv, env_list_t **env)
{
	env_list_t *a = *env, *b = *env, *c;

	while (a)
	{
		if (!strcmp(argv[1], a->name))
		{
			b->next = a->next;
			free_env_list_node(a);
			return;
		}
		b = a;
		a = a->next;
	}
	return;
}

void free_env_list(env_list_t **env)
{
	env_list_t *temp;

	while (*env)
	{
		temp = *env;
		*env = (*env)->next;
		free_env_list_node(temp);
	}
	free(env);
}

char **_get_str_env(env_list_t **env)
{
	env_list_t *a = *env;
	int count = 0, entry_len;
	char **str_env;
	char *entry;

	while (a)
	{
		count++;
		a = a->next;
	}

	str_env = malloc(sizeof(char *) * (count + 1));
	
	a = *env;
	count = 0;
	while (a)
	{
		entry_len = _strlen(a->name) + _strlen(a->value) + 2;
		entry = malloc(sizeof(char) * entry_len);
		strcpy(entry, a->name);
		entry = strcat(entry, "=");
		entry = strcat(entry, a->value);
		str_env[count] = entry;
		count++;
		a = a->next;
	}
	str_env[count] = NULL;
	return str_env;
}
