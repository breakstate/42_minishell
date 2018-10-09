#include "minishell.h"

void	free_2d_str(char **array)
{
	int	i;

	i = 0;
	while (array[i]){
	//	printf("freeing %s\n", array[i]);
		free(array[i]);
		i++;
	}
	free(array);
}

/*
ft_cleanup
*/

void	clean_up(t_myenv *myenv)
{
	free_2d_str(myenv->tokens);
	//free(myenv->tokens);
	free(myenv->line);
	//free(myenv->path);
	myenv->tokens = NULL;
	myenv->line = NULL;
	//myenv->path = getcwd(NULL, 0);
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
**	return value of specific environmental variable. NULL if not found
*/

char	*find(t_myenv *myenv, char *envvar)
{
	char	**keyval;
	char	*val;
	int		i;

	i = 0;
	while (myenv->env[i] != NULL)
	{
		if (ft_strncmp(envvar, myenv->env[i], ft_strlen(envvar)) == 0)
		{
			keyval = ft_strsplit(myenv->env[i], '=');
			val = ft_strdup(keyval[1]);
			free_2d_str(keyval);
			puts("successful free in find"); // debug
			return (val);
		}
		i++;
	}
	return (NULL);
}