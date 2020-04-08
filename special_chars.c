#include "protos.h"

int main(void)
{
	char *bork = strdup("ls -al /tmp && pwd # foo bar");;
	char **tokens;
	char *hash;
	
	hash = strchr(bork, '#');
	*hash = '\0';

	tokens = get_tokens(bork, "& ");

	return (0);
}
