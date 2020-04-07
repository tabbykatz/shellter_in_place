#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int i = 1;
	struct stat st;

	while (av[i])
	{
		if (!stat(av[i], &st))
			printf("%s FOUND\n", av[i]);
		else
			printf("%s NOT FOUND\n", av[i]);
		i++;
	}

	return (0);
}
