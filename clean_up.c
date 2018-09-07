#include "minishell.h"

void	clean_up(t_myenv *myenv)//char *tokens_i, char **tokens, char *line, char *path)
{
	int		i;

	i = 0;
	while (myenv->tokens[i])
	{
		free(myenv->tokens[i]);
		i++;
	}
	free(myenv->tokens);
	free(myenv->line);
	free(myenv->path);

	myenv->tokens = NULL;
	myenv->path = getcwd(NULL, 0);
	myenv->line = NULL;
}
