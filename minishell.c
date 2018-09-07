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

int		shell_helper(t_myenv *myenv)
{
	if (ft_strcmp("exit", myenv->tokens[0]) == 0)
	{
		clean_up(myenv);
		exit(0);
	}
	else
		launcher(myenv);
	//printf(">>%s\n", myenv->tokens[0]);--
	//free(myenv->tokens[i]);
	return (0);
}

void	shell(t_myenv *myenv)
{
	int		i;
	int		quit;

	quit = 0;
	myenv->exit_flag = 0;

	//fake_load();
	while (!(quit))
	{
		// i = 0; // why?
		myenv->tokens = NULL;
		myenv->path = getcwd(NULL, 0);
		ft_putstr(myenv->path); // debug
		ft_putstr("$> "); // prompt
		if (get_next_line(0, &(myenv->line)) < 1)
			return ;
		myenv->tokens = ft_strsplit(myenv->line, ' ');
		if (myenv->tokens[0])
			shell_helper(myenv);
		clean_up(myenv);
	}
}

/*
** Initialize myenv struct
*/

void	init(t_myenv *myenv)
{
	myenv->line = NULL;
	myenv->tokens = NULL;
	myenv->exit_flag = 0;
	myenv->path = NULL;
}

int		main(void)
{
	t_myenv myenv;
/*
	shell(&myenv);
*/
	myenv = init();
	//while(loop)
	//lexer
	//parser
	return (0);
}

// exit()
// parser()
// lexer()
// init()
// main()