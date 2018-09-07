#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include "libft/includes/libft.h"
# include "stdio.h" // debug

typedef struct	s_myenv
{
	char		*line;
	char		**tokens; // 
	int			exit_flag; // not sure if necessary
	char		*path; // current path (pwd)
}				t_myenv;

void	clean_up(t_pack *pack);//char *args_i, char **args, char *cmd, char *path);
void	fake_load(void);
void	launcher(t_pack *pack);

/*
**		Built-in function declarations:
*/

int		ft_cd(t_pack *pack);
int		ft_echo(t_pack *pack);
void	ft_exit(void);

#endif
