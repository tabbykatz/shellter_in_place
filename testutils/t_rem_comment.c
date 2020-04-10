#include "protos.h"

int main(void)
{
	char *bork = strdup("ls -al /tmp && pwd # foo bar");;
	
	rem_comments(bork);
	printf("%s\n", bork);
	return (0);
}
