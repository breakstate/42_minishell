#include "minishell.h"

// Everything needs a rework here considering that error handling has changed

void		ft_cd(t_myenv *myenv)
{
	if ((chdir(myenv->tokens[1]) == -1))
		myenv->error = 3;
}

void		ft_env(t_myenv *myenv)
{
	int i = 0;
	while (myenv->env[i])
	{
		if (ft_strcmp(myenv->env[i], "empty"))
			ft_putendl(myenv->env[i]);
		i++;
	}
}

void		ft_unsetenv(t_myenv *myenv)
{
	int		i;
	char	**args;
	char	*empty;

	if (!(myenv->tokens[1]) || (myenv->tokens[2]))
		ft_putendl("unsetenv error");
	i = 0;
	while (myenv->env[i] != NULL)
	{
		if (ft_strncmp(myenv->tokens[1], myenv->env[i], ft_strlen(myenv->tokens[1])) == 0)
		{
			free(myenv->env[i]);
			empty = ft_memalloc(6);
			ft_strcpy(empty, "empty");
			myenv->env[i] = empty;
			return;
		}
		i++;
	}
	ft_putendl("not found");
}

void		ft_setenv(t_myenv *myenv)
{
	char	**newenv;
	int		i;

	i = 0;
	newenv = (char**)malloc(sizeof(char*)* myenv->envsize + 1);
	while (myenv->env[i] != NULL)
	{
		newenv[i] = ft_strdup(myenv->env[i]);
		//printf("i = %d\n", i); // debug
		free(myenv->env[i]);
		i++;
	}
	newenv[i] = ft_strdup(myenv->tokens[1]);
	newenv[i + 1] = NULL;
	free(myenv->env);
	myenv->env = newenv;
	myenv->envsize++;
}

void	ft_echo(t_myenv *myenv)
{
	int		i;
	int		flag;

	flag = 0;
	i = 1;
	while (myenv->tokens[i] != NULL)
	{
		flag = 1;
		ft_putstr(myenv->tokens[i]);
		ft_putstr(" ");
		i++;
	}
	if (flag)
		ft_putendl("");
}

/*
int		ft_echo(t_myenv *myenv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while(myenv->tokens[i])
	{
		while (myenv->tokens[i][j])
		{
			if (myenv->tokens[i][j] != '"')
				ft_putchar(myenv->tokens[i][j]);
			else if (myenv->tokens[i][j] == '"' && j > 0 && myenv->tokens[i][j - 1] == 92)
				ft_putchar(92);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	return (0);
}
*/
/*
void		ft_echo(t_myenv *myenv)
{
	int		i;
	int		q_flag;

	i = 0;
	q_flag = 0;
	while (ft_isspace(myenv->line[i]))
		i++;
	while (!(ft_isspace(myenv->line[i])))
		i++;
	while (ft_isspace(myenv->line[i]))
		i++;
	while (myenv->line[i])
	{
		if (myenv->line[i] == '"' && myenv->line[i - 1] != 92 && q_flag == 0)
		{
			q_flag = 1;
			i++;
		}
		else if (myenv->line[i] == '"' && myenv->line[i - 1] != 92 && q_flag == 1)
		{
			q_flag = 0;
			i++;
		}
		if (q_flag == 1)
			ft_putchar(myenv->line[i]);
		else 
		{
			if (!(ft_isspace(myenv->line[i])))
				ft_putchar(myenv->line[i]);
			else if (myenv->line[i] != ' ' && myenv->line[i - 1] == ' ')
			{

				ft_putchar(' ');
			}
		}
		printf("|i = %c, i - 1 = %c|\n", myenv->line[i], myenv->line[i - 1]);
		i++;
	}
	ft_putchar('\n');
}
*/