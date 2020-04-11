#include "shell.h"

int isin_dir(char *term, char *dir)
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;

    folder = opendir(dir);
    if(folder == NULL)
    {
        perror("Unable to read directory");
        return(1);
    }

    while( (entry=readdir(folder)) )
    {
        files++;
	if (!strcmp(entry->d_name, term))
	{
		closedir(folder);
		return (1);
	}
    }

    closedir(folder);
    return(0);
}
