#include "shell.h"

/**
  * do_nothing - a dummy function
  * @nothing: a dummy integer
  */
void do_nothing(int nothing)
{}

/**
  * main - entry point
  * Return: 0
  */
int main(void)
{
	int exit_status = 0, last_return = 1, i;
	size_t line_size = 0;
	ssize_t getline_size;
	char **argv, *line = NULL;
	env_list_t **env;
	order_t **ops = malloc(sizeof(order_t *));
	order_t *a;
	char **argvv;
	
	signal(SIGINT, do_nothing);
	env = _initenv_list();
	while (1)
	{
		printf("ShiP$ ");
		getline_size = getline(&line, &line_size, stdin);
		line[getline_size - 1] = '\0';

		if (getline_size == -1)
		{
			free(line);
			free_env_list(env);
			free_ops(ops);
			return (0);
		}

		rem_comments(line);

		*ops = NULL;
		argvv = _get_cmds(line, ops);
		a = *ops;
		for (i = 0; argvv[i]; i++)
		{
			if (a)
			{
				if (!last_return || a->n == 3)
				{
					i++;
					a = a->next;
				}
			}

			argv = get_tokens(argvv[i], " ");

			if (!_strcmp(argv[0], "exit"))
			{
				if (argv[1])
					exit_status = _atoi(argv[1]);
				free(line);
				free_env_list(env);
				free_ops(ops);
				return (exit_status);
			}

			last_return = cmd_handler(argv, env);
		}
	}
	return (0);
}
