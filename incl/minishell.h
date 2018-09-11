#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h> // setenv

# include "stdio.h" // debug // REMOVE

/*
** my environment
*/

typedef struct	s_myenv
{
	char		*line; // line input by user on stdin
	char		**tokens; // tokenized line delimited by ' '
	int			loop; // exit flag for loop
	int			error; // error code
	char		*path; // current path (pwd)
	char		**env; // internal copy of environment
}				t_myenv;

/*
** utilities
*/

void	clean_up(t_myenv *myenv);
void	loadanimation(void); // debug // REMOVE
void	free_2d_str(char **array);
void	free_env(char **array);

/*
** parse.c
*/

int		isbuiltin(t_myenv *myenv);
void	execfunc(t_myenv *myenv);
void	execbuiltinfunc(t_myenv *myenv, int functype);
void	copy_env(t_myenv *myenv);

/*
** Builtins.c
*/

void	ft_cd(t_myenv *pack);
void	ft_echo(t_myenv *pack);
void	ft_pwd(t_myenv *pack);
void	ft_exit(void);
void	ft_env(t_myenv* myenv);
void	ft_unsetenv(t_myenv *myenv);

/*
** main.c
*/

void	myerror(t_myenv *myenv);
void	parser(t_myenv *myenv);
void	lexer(t_myenv *myenv);
void	init(t_myenv *myenv);

/*
** debug
*/

void	debugEnvPrint(t_myenv *myenv);

#endif
