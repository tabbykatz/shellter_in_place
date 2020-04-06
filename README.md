![](https://lh3.googleusercontent.com/KA6geT3NMPcKa-upirdwI-D7-q8bpu567zklmOme8_zKXp1c2M9_aAOpJ6hZeFrw9zV3tgTkWky3HbDsvGv4fYGsWiizxCKvTKho6jwUnU7pEiHZzAGAqLww9DCxnQCkEOjixiK-SiB7Q236XPTf052NAA8YJnYbx_bilCxE4xrymWuOkMH8tninBlQu_IFgvYe75PSBekJwBCPmoRzAtzOVoqKq8KNOS1lL0q9lFcenu-SLN_WV2puLBpCoisaaQ5qnz3IHh50DXgOJdM4ZL3vHpqKsJncERytq83JzjvJwMEZdTS_tTIY-GWIRGFcd4ilYkstTAo2J5IBAbqOifsbYE0c3f_KqPDgEzO7kEghU7QJ6H97fGvYfiKnWBkOLo-uL3udlFtpIpEKjoO657Yqr9fuICOlP--DCio4jbTiN-szVoZnQJZLqETkuN1i6FtzdKaH4O1S-y7Os4d6V0tVO_0mhC1nnwW-iBSBrOtQ3Qfubt4yJsRvN1vmaUVOJOw2PiKawhdYc3ZGnnHy8k_PXAaM6FlzkvviRd4L2Qk4uy5wSvwFdJ6cwBZP2MybDYjC01NUxdYrLvNVVUTlwLqa98CjT80z7ZAbIMRuuLwJSv7m9_ZzFWrzP9mDI3Mnqo0xff313E5dCY0AaO_Q16IS47pb9TY2WGYLq_bCJv3dmv7Ehw1Jz8ghynrVH=w2214-h350-no)
# 0x15. C - Simple Shell <br />

Year 1 - Low-level programming & Algorithm ― Linux and Unix system programming - Holberton School
### Team:
[Zac Woll](https://github.com/zacwoll)
[Tabitha O'Melay](https://github.com/tabbykatz)

## Compilation
Our shell is compiled this way: <br />
`gcc -Wall -Werror -Wextra -pedantic simple_shell.c simple_helpers.c pathfinder.c built_ins.c -o sh` <br />
`./sh`

## Commands
### At minimum, this shell handles the following commands to display file contents on the command line:
`cat`: Concatenates the file and gives output on standard output. <br />
`less`: View files instead of opening the file. Allows backward and forward movement. <br />
`more`: Page through text one screenful at a time. <br />
### This shell handles the following file and directory manipulation commands:
`mkdir`: Creates a directory and accepts directory name as next parameter. <br />
`rm` and `rm -r`: Used to delete files and directories. <br />
`touch`: Creates a file or updates a file. <br />

### And the following basic command line navigation commands:

`ls`: Displays list of all files and folders in the current directory. <br />
`cd`: Changes the directory. <br />
`du`: Shows disk usage. <br />
`pwd`: Shows the present working directory. <br />
`man` + `cmd`: Shows the manual entry for any given command. <br />
`exit`: Quits the simple_shell program.
# Resources
[Unix shell wiki](https://en.wikipedia.org/wiki/Unix_shell)
[Thompson shell wiki](https://en.wikipedia.org/wiki/Thompson_shell)
[Ken Thompson wiki](https://en.wikipedia.org/wiki/Ken_Thompson)
[Everything you need to know to start coding your own shell (Holberton Intranet)](https://intranet.hbtn.io/concepts/64)
[Understanding fork() system call for new process creation](https://youtu.be/PwxTbksJ2fo)
[Linux fork() Introduction](https://youtu.be/9seb8hddeK4)
[Tutorial - Write a Shell in C (Stephen Brennan)](https://brennan.io/2015/01/16/write-a-shell-in-c/)
[The getline() Function](https://c-for-dummies.com/blog/?p=1112)
[Input/Output on Streams](http://kirste.userpage.fu-berlin.de/chemnet/use/info/libc/libc_7.html)
[Writing a Unix Shell (Cracking The Code) Part I](https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/)
[Writing a Unix Shell (Cracking The Code) Part II](https://indradhanush.github.io/blog/writing-a-unix-shell-part-2/)
[Making your own Linux Shell in C (GeeksForGeeks)](https://www.geeksforgeeks.org/making-linux-shell-c/)
[C library function - strtok()](https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)
# Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

# Requirements
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)

# More Info

## Output
- Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

Example of error with sh: <br />

Example of same error with our program hsh: <br />

## Functions and system calls

| List of allowed functions and system calls: | |
|--|--|
| access (man 2 access)  | chdir (man 2 chdir) |
| close (man 2 close) | closedir (man 3 closedir) |
| execve (man 2 execve) | exit (man 3 exit) |
| _exit (man 2 _exit) | fflush (man 3 fflush) |
| fork (man 2 fork) | free (man 3 free) |
| getline (man 3 getline) | isatty (man 3 isatty) |
| kill (man 2 kill) | malloc (man 3 malloc) |
| open (man 2 open) | opendir (man 3 opendir) |
| perror (man 3 perror) | read (man 2 read) |
| readdir (man 3 readdir) | signal (man 2 signal) |
| stat (__xstat) (man 2 stat) | lstat (__lxstat) (man 2 lstat) |
| fstat (__fxstat) (man 2 fstat) | strtok (man 3 strtok) |
| wait (man 2 wait) | waitpid (man 2 waitpid) |
| wait3 (man 2 wait3) | wait4 (man 2 wait4) |
| write (man 2 write) |  |

## Task Instructions
Task 0.
-  Write a `README`
-   Write a `man` for your shell.
-   You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see [Docker](https://intranet.hbtn.io/rltoken/xvzr_eas4Z83gL3Fp0slag "Docker")
-> Repo: GitHub repository: `simple_shell`
- File: `README.md, man_1_simple_shell, AUTHORS`

Task 1.
- Betty would be proud. Write beautiful code that passes the Betty checks.
->  Repo: GitHub repository: `simple_shell`

Task 2.
- Contribute to a test suite for your shell.
- Forked inspiration from [this example](https://intranet.hbtn.io/rltoken/3968uYdoP1XylGPBqmAt5g "this example")
-> Repo:  [sf0120 Test Suite](https://github.com/tabbykatz/sf0120_shell_suite)

Task 3.
- Simple shell 0.1
- Write a UNIX command line interpreter.
-   Usage: `simple_shell`
--> Repo: GitHub repository: `simple_shell`


Task 4.
-  Simple shell 0.1.1
-   Write your own `getline` function
-   Use a buffer to read many chars at once and call the least possible the `read` system call
-   You will need to use `static` variables
-   You are not allowed to use `getline`

You don’t have to:
-   be able to move the cursor
-> Repo: GitHub repository: `simple_shell`

Task 5.
- Simple shell 0.1 +
-   Handle command lines with arguments
-> Repo: GitHub repository: `simple_shell`

Task 6.
- Simple shell 0.2.1
-   You are not allowed to use `strtok`
-> Repo:  GitHub repository: `simple_shell`

Task 7.
- Simple shell 0.3
- Handle the `PATH`
-> Repo: GitHub repository: `simple_shell`

Task 8.
- Simple shell 0.4
-  Implement the `exit` built-in, that exits the shell
-   Usage: `exit`
-   You don’t have to handle any argument to the built-in `exit`
-> Repo: GitHub repository: `simple_shell`

Task 9.
- Simple shell 0.4.1
-  handle arguments for the built-in `exit`
-  Usage: `exit status`, where `status` is an integer used to exit the shell
-> Repo: GitHub repository: `simple_shell`

Task 10.
- Simple shell 0.4.2
- Handle `Ctrl+C`: your shell should not quit when the user inputs `^C`
-> Repo: GitHub repository: `simple_shell`

Task 11.
- Simple shell 1.0
- Implement the `env` **built-in**, that prints the current environment
 -> Repo: GitHub repository: `simple_shell`

Task 12.
- setenv, unsetenv
- Implement the `setenv` and `unsetenv` builtin commands

-   `setenv`
    -   Initialize a new environment variable, or modify an existing one
    -   Command syntax: `setenv VARIABLE VALUE`
    -   Should print something on stderr on failure
-   `unsetenv`
    -   Remove an environment variable
    -   Command syntax: `unsetenv VARIABLE`
    -   Should print something on stderr on failure
    -> Repo: GitHub repository: `simple_shell`

Task 13.
- cd
- Implement the builtin command `cd`:
-   Changes the current directory of the process.
-   Command syntax: `cd [DIRECTORY]`
-   If no argument is given to `cd` the command must be interpreted like `cd $HOME`
-   You have to handle the command `cd -`
-   You have to update the environment variable `PWD` when you change directory
-> Repo: GitHub repository: `simple_shell`

Task 14.
- ;
- Handle the commands separator `;`
-> Repo: GitHub repository: `simple_shell`

Task 15.
- && and ||
- Handle the `&&` and `||` shell logical operators
-> Repo: GitHub repository: `simple_shell`

Task 16.
- alias
-  Implement the `alias` builtin command
-  Usage: `alias [name[='value'] ...]`
    -   `alias`: Prints a list of all aliases, one per line, in the form `name='value'`
    -   `alias name [name2 ...]`: Prints the aliases `name`, `name2`, etc 1 per line, in the form `name='value'`
    -   `alias name='value' [...]`: Defines an alias for each `name` whose `value` is given. If `name` is already an alias, replaces its value with `value`
   -> Repo: GitHub repository: `simple_shell`

Task 17.
- Variables
-   Handle variables replacement
-   Handle the `$?` variable
-   Handle the `$$` variable
 -> Repo: GitHub repository: `simple_shell`

Task 18.
- Comments
- Handle comments (`#`)
 -> Repo: GitHub repository: `simple_shell`

Task 19.
- help
-  Implement the `help` built-in
-   Usage: `help [BUILTIN]`
 -> Repo: GitHub repository: `simple_shell`

Task 20.
- history
-  Implement the history built-in, without any argument
-   The `history` built-in displays the history list, one command by line, preceded with line numbers (starting at `0`)
-   On `exit`, write the entire history, without line numbers, to a file named `.simple_shell_history` in the directory `$HOME`
-   When the shell starts, read the file `.simple_shell_history` in the directory `$HOME` if it exists, and set the first line number to the total number of lines in the file modulo `4096`
 -> Repo: GitHub repository: `simple_shell`

Task 21.
- File as input
- -   Usage: `simple_shell [filename]`
-   Your shell can take a file as a command line argument
-   The file contains all the commands that your shell should run before exiting
-   The file should contain one command per line
-   In this mode, the shell should not print a prompt and should not read from `stdin`
 -> Repo: GitHub repository: `simple_shell`

Task 22.
- What happens when you type ls -l in the shell
- Write a blog post describing step by step what happens when you type `ls -l` and hit Enter in a shell.
-> Blog Post (add url)

