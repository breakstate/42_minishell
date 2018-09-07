#include "minishell.h"

// Everything needs a rework here considering that error handling has changed

int		ft_cd(t_myenv *myenv)
{
	if ((chdir(myenv->tokens[1]) == -1))
		return (-1);
	return (0);
}

int		ft_echo(t_myenv *myenv)
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
	return (0);
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
