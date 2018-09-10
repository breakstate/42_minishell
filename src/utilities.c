#include "minishell.h"

void	free_2d_str(char **array)
{
	int	i;

	i = -1;
	while (array[++i]){
		printf("freeing %s\n", array[i]);
		free(array[i]);
	}
}

void	free_env(char **array)
{
	int	i;

	i = -1;
	while (array[++i] != NULL){
		printf("array = %s\n", array[i]);
		free(array[i]);
	}
}

void	clean_up(t_myenv *myenv)
{
	free_2d_str(myenv->tokens);
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

/*
ft_cleanup
*/