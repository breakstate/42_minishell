/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:38:27 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/24 16:47:24 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"

void	shell(void)
{
	char	*cmd;
	char	**args;
	int		i;
	int		exit_flag;
	char	*path;

	exit_flag = 0;
	fake_load();
	while (42)
	{
		i = 0;
		cmd = NULL;
		args = NULL;
		path = getcwd(NULL, 0);
		ft_putstr(path);
		ft_putstr("$> ");
		if (get_next_line(0, &cmd) < 1)
		{
			return ;
		}
		args = ft_strsplit(cmd, ' ');
		if (args[0])
			launcher(args);
		while (args[i])
		{
			//if (!(ft_strcmp("exit", args[0])))
			//{
			//	clean_up(&args[i], &args, &cmd);
			//	exit(0);
			//}
			printf(">>%s\n", args[i]);
			//free(args[i]);
			i++;
		}
		clean_up(&args[i], &args, &cmd);
	}
}

int		main()
{
	shell();
	return (0);
}
