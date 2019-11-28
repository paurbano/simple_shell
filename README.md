# SIMPLE SHELL
Repository for Simple Shell project

# Description

UNIX command line interpreter. Execute commands read from the standard input.
No handle special characters, env , history and help built-in, file as input, comments, alias, && and ||.

# Requirements

All our files are compiled on Ubuntu 14.04 LTS
The C program and functions are compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

# Files

+ AUTHORS
+ README.md
+ _builtin.c_
+ _exec.c
+ _main.c
+ _prompt.c
+ _separaArgs.c
+ _strtok.c
+ functions.c
+ man_3_shell
+ shell.h

# Compilation

 - `$gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`


Execute the file hsh

 - `vagrant@vagrant-ubuntu-trusty-64:~$./hsh`



# Running the tests

The shell works like this in interactive mode:

 - `$ ./hsh`
 - `($) /bin/ls`
 - `hsh main.c shell.c`
 - `($)`
 - `($) exit`
 - `$`

Also in non-interactive mode:

 - `$ echo "/bin/ls" | ./hsh`
 - `hsh main.c shell.c test_ls_2`
 - `$`
 - `/bin/ls`
 - `/bin/ls`
 - `$`
 - `$ cat test_ls_2 | ./hsh`
 - `hsh main.c shell.c test_ls_2`
 - `hsh main.c shell.c test_ls_2`
 - `$`

# Usage

All the files are to be compiled on Ubuntu 14.04 LTS Compile your code with

 - `$gcc -Wall -Werror -Wextra -pedantic *.c`
 - `$ ./hsh`

type the command in interactive or non-interactive mode

# Repository Functions

| Function                              | Description |
| ---------                             | ----- |
| char * _prompt(void)                     | display the dollar sign as prompt and get the command from standard input |
| char **_separaArgs(char *)   `            | Takes the string from the standard input and separe it in tokens.         |
| void _exec(char **, char **)             | Execute the command taken from the first position in tokens.              |
| char *_strtok(char *str, char *del)      | Divides in tokens the string according to the delimeter del.|
| int _builtin (char **cmd, char **)       | Launch bultins as exit, cd.|
|void hsh_cd(char **cmd)                   | implements the cd built-in.|
| void hsh_env(char **env)                 |Prints the environment variables.|
|char *get_env_var(char *variable, char **env)|Prints the environment variables.|
|char *get_cmd_path(char *varvalue, char *command)|returns the PATH.|
|int _strlen(char *s)                      | returns the lenght of a string.|
| int _strcmp(char *s1, char *s2)          | returns the result of compare to strings.|
|char *_strcat(char *dest, char *src)      | concatenate two strings.|
|void ctrc(int)                            | Handle a singal SIGNINT.|
|void exitp(char *,char *)                 | Implements the exit buitl-in.|

# Libraries
- #include <stdio.h>
- #include <stdlib.h>
- #include <unistd.h>
- #include <string.h>
- #include <errno.h>
- #include <sys/types.h>
- #include <sys/wait.h>
- #include <sys/stat.h>
- #define BUFFSIZE 1024

# List of allowed functions and system calls

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)


# Example
- `vagrant@vagrant-ubuntu-trusty-64:~/shell$./hsh`
- `$ ls`
- `betty-doc.pl  betty.sh  betty-style.pl  install.sh  LICENSE  man  README.md  tests  test.sh`

Interactive

- `$ ./hsh`
- `$ ls`
- `betty-doc.pl  betty.sh  betty-style.pl  install.shbetty-doc.pl  betty.sh  betty-style.pl  install.sh`

Non interactive

- `$ echo "/bin/ls" | ./hsh`
- `hsh main.c shell.c test_ls_2`
- `$ cat test_ls_2`
- `/bin/ls`
- `/bin/ls`
- `$ cat test_ls_2 | ./hsh`
- `hsh main.c shell.c test_ls_2`
- `hsh main.c shell.c test_ls_2`

# Secuence Diagram
![](https://github.com/paurbano/simple_shell/blob/master/sequence_diagram.png)

# Authors
- Pablo Andrés Urbano de la Cruz
- Aiko Mi

