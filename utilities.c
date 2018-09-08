#include "minishell.h"

void	clean_up(t_myenv *myenv)
{
	int	i;

	i = -1;
	while (myenv->tokens[i++])
		free(myenv->tokens[i]);
	free(myenv->tokens);
	free(myenv->line);
	free(myenv->path);
	myenv->tokens = NULL;
	myenv->line = NULL;
	myenv->path = getcwd(NULL, 0);
}

void	fake_load(void)
{
	ft_putstr("\n");
	ft_putstr("$> **WELCOME TO MINISHELL**\n");
	ft_putstr(".");
	sleep(1);
	ft_putstr(".");
	sleep(1);
	ft_putendl(".");
}
