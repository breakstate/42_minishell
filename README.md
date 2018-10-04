# 42_minishell (WIP)
### Parent school: Ecole 42
### School: WeThinkCode_ Johannesburg
### Year: 1
### Semester: 1
### Branch: Unix

#### Summary:
The objective of this project is to create the simplest implementation of a Shell (mini UNIX command interpreter).

#### Learning opportunities:
- Get acquainted with the core of Unix system
- Process creation
- Fork and execve
- Lexing and parsing input
- The inner working of Shells

#### Instructions
- Executable to be named minishell
- You must submit a Makefile
- Use of libft project allowed and encouraged
- No global variables
- Project must be Norminette compliant (42 C programming standard)
- Handle errors - project must not quit in an unexpected manner (Seg fault, bus error, double free, etc)
- No memory leaks
- Include author file 

##### Allowed functions: 
- malloc, free
- access
- open, close, read, write
- opendir, readdir, closedir
- getcwd, chdir
- stat, lstat, fstat
- fork, execve
- wait, waitpid, wait3, wait4
- signal, kill
- exit

#### Overview:
This project is about creating a simple shell. The program must display a prompt and wait for input, validated by the enter key. The shell must implement `echo, cd, setenv, unsetenv, env and exit` and must execute built-in executables pointed to by the PATH environment variable. The prompt must be given back after execution.

#### Usage:
Run binary from command line.
