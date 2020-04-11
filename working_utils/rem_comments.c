#include "shell.h"

void rem_comments(char *str)
{
	char *del = strchr(str, '#');

	if (del)
		*del = '\0';
}
