#include "shell.h"

int main() 
{
	char **env = _initenv();
    // printing current working directory 
    printf("%s\n", _getenv("PWD", &env)); 
  
    // using the command 
    chdir(".."); 
  
    // printing current working directory 
    printf("%s\n", _getenv("OLDPWD", &env)); 
  
    // after chdir is executed 
    return 0; 
}
