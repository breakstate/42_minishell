#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include "libft/includes/libft.h"
# include "stdio.h" // debug

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
}				t_myenv;



void	clean_up(t_myenv *myenv);
void	loadanimation(void);

/*
** parse.c
*/

int		isbuiltin(t_myenv *myenv);
void	launchbuiltin();

/*
** Built-in functions:
*/

void	ft_cd(t_myenv *pack);
void	ft_echo(t_myenv *pack);
void	ft_pwd(t_myenv *pack);
void	ft_exit(void);

/*
** main.c
*/

void	myerror(t_myenv *myenv);
void	parser(t_myenv *myenv);
void	lexer(t_myenv *myenv);
void	init(t_myenv *myenv);
int		main(void);

#endif
