#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char buf[BUFSIZ];
	char *cp;

	printf("BUFSIZ = %d\n", BUFSIZ);
	cp = getcwd(buf, sizeof(buf));
	printf("Current dir: %s\n", buf);

	printf("Changing to ..\n");
	chdir("..");			/* `cd ..' */

	cp = getcwd(buf, sizeof(buf));
	printf("Current dir is now: %s, %zu bytes\n", buf, strlen(buf));
	return 0;
}
