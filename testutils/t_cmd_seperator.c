#include "shell.h"

/* this function tests the get_cmds.c
 * compile with get_cmds.c & get_tokens_strtok (the version
 * of get_tokens with strtok not _strtok)
 */
int main(void)
{
	char *line = strdup("cd /butts && pwd || ls");
	int i;
	order_t **ops = malloc(sizeof(order_t *));
	order_t *a;
	char **argvv;

	*ops = NULL;
	argvv = _get_cmds(line, ops);

	a = *ops;

	printf("argvv[i]\n");
	for (i = 0; argvv[i]; i++)
	{
		printf("%d: %s\n", i, argvv[i]);
	}
	printf("order_t[i]\n");
	for (i = 0; a; i++)
	{
		printf("%d: %d\n", i, a->n);
		a = a->next;
	}

	free(line);
	free(argvv);
	free_ops(ops);
}
