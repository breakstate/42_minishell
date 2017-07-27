#include "minishell.h"

void	clean_up(char *args_i, char **args, char *cmd, char *path)
{
	free(args_i);
	free(args);
	free(cmd);
	free(path);
}
