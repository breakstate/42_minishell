#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include "libft/includes/libft.h"
# include "stdio.h" // debug

typedef struct	s_myenv
{
	char		*line;
	char		**tokens; // 
//	int			exit_flag; // not sure if necessary // replacing with loop
	int			loop; // 
	int			error; // error code
	char		*path; // current path (pwd)
}				t_myenv;

void	clean_up(t_myenv *pack);//char *args_i, char **args, char *cmd, char *path);
void	fake_load(void);
void	launcher(t_myenv *pack);

/*
** parse.c
*/

int		isbuiltin(t_myenv *myenv);
void	launchbuiltin();

/*
**		Built-in function declarations:
*/

void	ft_cd(t_myenv *pack);
void	ft_echo(t_myenv *pack);
void	ft_pwd(t_myenv *pack);
void	ft_exit(void);

#endif
