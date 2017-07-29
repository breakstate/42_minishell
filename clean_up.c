#include "minishell.h"

void	clean_up(t_pack *pack)//char *args_i, char **args, char *cmd, char *path)
{
	int		i;

	i = 0;
	while (pack->args[i])
	{
		free(pack->args[i]);
		i++;
	}
	free(pack->args);
	free(pack->cmd);
	free(pack->path);
}
