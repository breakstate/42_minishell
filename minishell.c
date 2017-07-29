/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:38:27 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/29 14:35:41 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"

int		shell_helper(t_pack *pack)
{
	if (ft_strcmp("exit", pack->args[0]) == 0)
	{
		clean_up(pack);
		exit(0);
	}
	else
		launcher(pack);
	//printf(">>%s\n", pack->args[0]);--
	//free(pack->args[i]);
	return (0);
}

void	shell(t_pack *pack)
{
	int		i;

	pack->exit_flag = 0;
	fake_load();
	while (42)
	{
		i = 0;
		pack->args = NULL;
		pack->path = getcwd(NULL, 0);
		ft_putstr(pack->path);
		ft_putstr("$> ");
		if (get_next_line(0, &(pack->cmd)) < 1)
			return ;
		pack->args = ft_strsplit(pack->cmd, ' ');
		if (pack->args[0])
			shell_helper(pack);
		clean_up(pack);
	}
}

int		main(void)
{
	t_pack pack;

	pack.cmd = NULL;
	pack.args = NULL;
	pack.exit_flag = 0;
	pack.path = NULL;
	shell(&pack);
	return (0);
}
