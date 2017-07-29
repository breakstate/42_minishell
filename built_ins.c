#include "minishell.h"

int		ft_cd(t_pack *pack)
{
	if ((chdir(pack->args[1]) == -1))
		return (-1);
	return (0);
}

int		ft_echo(t_pack *pack)
{
	int		i;
	int		q_flag;

	i = 0;
	q_flag = 0;
	while (ft_isspace(pack->cmd[i]))
		i++;
	while (!(ft_isspace(pack->cmd[i])))
		i++;
	while (ft_isspace(pack->cmd[i]))
		i++;
	while (pack->cmd[i])
	{
		if (pack->cmd[i] == '"' && pack->cmd[i - 1] != 92 && q_flag == 0)
		{
			q_flag = 1;
			i++;
		}
		else if (pack->cmd[i] == '"' && pack->cmd[i - 1] != 92 && q_flag == 1)
		{
			q_flag = 0;
			i++;
		}
		if (q_flag == 1)
			ft_putchar(pack->cmd[i]);
		else 
		{
			if (!(ft_isspace(pack->cmd[i])))
				ft_putchar(pack->cmd[i]);
			else if (pack->cmd[i] != ' ' && pack->cmd[i - 1] == ' ')
			{

				ft_putchar(' ');
			}
		}
		printf("|i = %c, i - 1 = %c|\n", pack->cmd[i], pack->cmd[i - 1]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
/*
int		ft_echo(t_pack *pack)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while(pack->args[i])
	{
		while (pack->args[i][j])
		{
			if (pack->args[i][j] != '"')
				ft_putchar(pack->args[i][j]);
			else if (pack->args[i][j] == '"' && j > 0 && pack->args[i][j - 1] == 92)
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
