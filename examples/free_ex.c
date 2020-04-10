#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void double_free(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		free(argv[i]);
	}
	free(argv);
}

int main(void)
{
	char *fruit[] = {"apples", "bananas", "oranges"};
	int i;
	char **fruit_copy;

	fruit_copy = malloc(sizeof(char *) * 3);
	for (i = 0; fruit[i]; i++)
	{
		fruit_copy[i] = strdup(fruit[i]);
	}
	double_free(fruit_copy);
	return (0);
}
