#include "minishell.h"

void	launcher(char **args)
{
	if (ft_strcmp(args[0], "cd") == 0 && args[1])
		ft_cd(args[1]);
}
