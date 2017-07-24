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

void	shell(void)
{
	char	*cmd;
	char	**args;
	
	ft_putstr("\n");
	ft_putstr("$> **INITIATING SHELL**\n");
	sleep(1);
	ft_putstr(".");
	sleep(1);
	ft_putstr(".");
	sleep(1);
	ft_putstr(".");
	sleep(1);
	ft_putstr("\n");
	printf("%s\n", getcwd(NULL, 20));
	while (42)
	{
		ft_putstr("$> ");
		if (get_next_line(0, &cmd) < 0)
			return ;
		//args = ft_strsplit(cmd);
	}
}

int		main()
{
	shell();
	return (0);
}
