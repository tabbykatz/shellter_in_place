#include "protos.h"
/* test of _getenv */
int main(void)
{
	char **env = _initenv();

	printf("%s\n", _getenv("PATH", &env));
	return (0);
}
