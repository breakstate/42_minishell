#include "minishell.h"

void	clean_up(char **args_i, char ***args, char **cmd)
{
	int		i;

	i = 0;
	free(*args_i);
	free(*args);
	free(*cmd);
}
