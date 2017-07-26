#include "minishell.h"

int		ft_cd(char *arg)
{
	if (!(chdir(arg) == 0))
		return (-1);
	return (0);
}

void	ft_exit(void)
{
	exit(0);
}
