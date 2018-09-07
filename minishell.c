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

void	myerror(t_myenv *myenv)
{
	//1 = read error
	//2 = parse error
	//3 = chdir error
}

void	parser(t_myenv *myenv)
{
	int	ft_ptr;

	if ((ft_ptr = isbuiltin(myenv)) > -1)
		launchbuiltin(myenv, ft_ptr);
	//else if (ft_ptr < -1)
		//launchnonbuiltin
	//automatic else exit
}

void	lexer(t_myenv *myenv)
{
	if (get_next_line(0, &(myenv->line)) < 1) // may not even need line in myenv struct
		return;
	//myenv->error = 1; // read error (maybe showoff with enum) // may be unecessary
	myenv->tokens = ft_strsplit(myenv->line, ' ');
	if (myenv->tokens[0])
		parser(myenv);
}

/*
** Initialize myenv struct
*/

void	init(t_myenv *myenv)
{
	myenv->line = NULL;
	myenv->tokens = NULL;
	myenv->loop = 1;
	myenv->path = NULL;
	myenv->error = 0;
}

int		main(void)
{
	t_myenv myenv;
/*
	shell(&myenv);
*/
	init(&myenv);
	myenv.path = getcwd(NULL, 0);
	while(myenv.loop)
	{
		ft_putstr("$> "); // prompt
		lexer(&myenv);
		//parser(&myenv);
		myerror(&myenv); // predefined error messages based on custom error codes
		clean_up(&myenv);
	}
	free(myenv.path);
	return (0);
}

// exit()
// parser()
// lexer()
// init()
// main()

// echo, cd, setenv, unsetenv, env, exit.
// $, ~