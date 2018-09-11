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
	int		functype;
	pid_t	childpid;// i don't think this makes sense in this scope // looks like it does
	int		status;

	functype = isbuiltin(myenv);
	if (functype > -1)
		execbuiltinfunc(myenv, functype);
	else if (functype < -1)
	{
		if ((childpid = fork()) == 0)
			execfunc(myenv); // calls execve
		else
			wait(&status); // test
	}
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

/*
** entry point and main loop of shell
*/

int		main(int argc, char **argv, char **envp)
{
	t_myenv myenv;
	extern char **environ;

	//loadanimation();
	copy_env(&myenv);
	init(&myenv);
	myenv.path = getcwd(NULL, 0);
	while(myenv.loop)
	{
		ft_putstr("$> "); // prompt
		lexer(&myenv);
		myerror(&myenv); // predefined error messages based on custom error codes
		clean_up(&myenv);
	}
	free(myenv.path);
	free_2d_str(myenv.env);
	return (0);
}

// echo, cd, setenv, unsetenv, env, exit.
// $, ~