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

/*
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
	myenv->loop = 0;

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
*/

void	myerror(t_myenv *myenv)
{
	//1 = read error
	//2 = parse error
}

void	parser(t_myenv *myenv)
{
	int	ft_ptr;

	if ((ft_ptr = isbuiltin(myenv)) > -1)
		launchbuiltin(myenv, ft_ptr);
	//else
		//launchnonbuiltin
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
	while(myenv.loop)
	{
		ft_putstr("$> "); // prompt
		lexer(&myenv);
		//parser(&myenv);
		myerror(&myenv); // predefined error messages based on custom error codes
		clean_up(&myenv);
	}
	return (0);
}

// exit()
// parser()
// lexer()
// init()
// main()

// echo, cd, setenv, unsetenv, env, exit.
// $, ~