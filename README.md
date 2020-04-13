![Ship$](/shellimg.jpeg)

# Ship$: SHELLter in Place<br />

Year 1 - Low-level programming & Algorithm ― Linux and Unix system programming - Holberton School

### Ship$
Shellter in Place, or Ship$, is a simple command line interpreter written in C.

### Deployment
This program was built during the COVID-19 pandemic & "Shelter in Place" order in California, USA.

### Compilation
Ship$ is compiled this way: <br />
 `-Wall -Werror -Wextra -pedantic *.c -o hsh`

### To run the shell
 `./hsh`</br>

### Commands
Ship$ runs executable commands in the PATH, and handles the following:
* `exit [status]`
* `env`
* `setenv`
* `unsetenv`
* `cd`

Ship$ is also built to handle:
* logical `&&` & `||`
* comments beginning with `#`
* commands separator `;`
* `Ctrl-D`

### Example Usage
* This shell takes input the same as a standard Unix shell.  After running the executable `hsh`, enter desired input and press return.
* `ls -l`
* `exit 98`
* `cd ..`

### Release History
* 0.0.1 - First release - 17 Apr 2020

### About
All files were created and compiled on `Ubuntu 14.04.4 LTS` using `GCC 4.8.4` with the following flags: `-Wall -Werror -Wextra -pedantic`

### Authors
* Zac Woll [Github](https://github.com/zacwoll) - [Twitter](https://twitter.com/ZakWoll)
* Tabitha O'Melay [Github](https://github.com/tabbykatz) - [Twitter](https://twitter.com/tabby__katz)


