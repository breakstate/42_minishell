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

#include "libft.h"
#include "stdio.h"

void	shell(void)
{
	char	*cmd;
	char	**args;
	int		i;

	ft_putstr("\n");
	ft_putstr("$> **SHELL INITIATED**\n");
	ft_putstr("\n");
	while (42)
	{
		i = 0;
		cmd = NULL;
		args = NULL;
		ft_putstr("$> ");
		if (get_next_line(0, &cmd) < 1)
		{
			return ;
		}
		args = ft_strsplit(cmd, ' ');
		while (args[i])
		{
			printf("%s\n", args[i]);
			free(args[i]);
			i++;
		}
		free(args[i]);
		free(args);
		free(cmd);
	}
}

int		main()
{
	shell();
	return (0);
}
