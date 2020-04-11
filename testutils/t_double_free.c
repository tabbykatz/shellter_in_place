#include <stdlib.h>

/* this file tests the double_free fnc */

int main(void)
{
	char *fruit[] = {"apples", "bananas", "oranges", NULL};
	int i, fruit_size = 4;
	char **fruit_copy;

	fruit_copy = malloc(sizeof(char *) * fruit_size);
	for (i = 0; fruit[i]; i++)
	{
		fruit_copy[i] = strdup(fruit[i]);
	}
	double_free(fruit_copy);
	return (0);
}
