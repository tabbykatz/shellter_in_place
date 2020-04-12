#include "shell.h"

void *op_push_end(order_t **ops, int n)
{
	order_t *a, *b;

	if (!ops)
		return (NULL);

	a = malloc(sizeof(order_t));
	if (!a)
		return (NULL);

	a->n = n;
	a->next = NULL;

	if (!*ops)
	{
		*ops = a;
		return (a);
	}

	b = *ops;
	while (b->next)
	{
		b = b->next;
	}
	b->next = a;

	return (a);
}

char **_get_cmds(char *line, order_t **ops)
{
	int i;
	char **argvv;

	for (i = 0; line[i]; i++)
	{
		if (line[i] == '&')
		{
			if (line[i + 1] == '&')
			{
				op_push_end(ops, 2);
				i++;
			}
		}
		if (line[i] == '|')
		{
			if (line[i + 1] == '|')
			{
				op_push_end(ops, 3);
				i++;
			}
		}
		if (line[i] == ';')
			op_push_end(ops, 1);
	}
	argvv = get_tokens(line, "&|;");
	return (argvv);
}

void free_ops(order_t **ops)
{
	order_t *a;
	while (*ops)
	{
		a = *ops;
		*ops = (*ops)->next;
		free(a);
	}
	free(ops);
}
