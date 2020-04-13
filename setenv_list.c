#include "shell.h"

/**
  * _initenv_list - initialize a env_list
  */
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

/**
  * printenv_list - prints a env_list
  * @env: environment linked list
  */
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

/**
  * _getenv_list_value - get's a env_list node's value from a name
  * @name: char * to search for
  * @env: environment linked list
  * Return: char * containing nodes value
  */
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

/** 
  * _getenv_list_node - get's a env_list node
  * @name: name to search for
  * @env: environment linked list
  * Return: env_list_t * node or NULL
  */
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

/**
  * _setenv_list - set environment variable in list
  * @argv: argument vector
  * @env: environment linked list
  */
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

/**
  * free_env_list_node - free's an env_list node
  * @node: env_list node to be free'd
  */
void free_env_list_node(env_list_t *node)
{
	free(node->name);
	free(node->value);
	free(node);
}

/**
  * _unsetenv_list - unset's a env_list var
  * @argv: argument vector
  * @env: environment linked list
  */
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

/**
  * free_env_list - free's an env_list list
  * @env: environment linked list
  */
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

/**
  * _get_str_env - converts linked list to str[] for execve
  * @env: environment linked list
  */
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
