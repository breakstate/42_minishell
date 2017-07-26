#ifndef _MINISHELL_H
# define _MINISHELL_H_

# include "libft/includes/libft.h"

void	clean_up(char **args_i, char ***args, char **cmd);
void	fake_load(void);
void	launcher(char **args);
int		ft_cd(char *arg);
void	ft_exit(void);

#endif
