#include "minishell.h"

int		isbuiltin(t_myenv *myenv)
{
	int		ret;

	ret = -1;
	if (ft_strcmp(myenv->tokens[0], "cd") == 0)
		ret = 0;
	else if (ft_strcmp(myenv->tokens[0], "echo") == 0)
		ret = 1;
	else if (ft_strcmp(myenv->tokens[0], "env") == 0)
		ret = 2;
	else if (ft_strcmp(myenv->tokens[0], "setenv") == 0)
		ret = 3;
	else if (ft_strcmp(myenv->tokens[0], "unsetenv") == 0)
		ret = 4;
	else if (ft_strcmp(myenv->tokens[0], "pwd") == 0)
		ret = 5;
	else if (ft_strcmp(myenv->tokens[0], "exit") == 0) // temp pending free method
		myenv->loop = 0; // return -1 by default
	return (ret);
}

void	execbuiltinfunc(t_myenv *myenv, int functype)
{
	void (*foo[6])(t_myenv *);

	foo[0] = &ft_cd;
	foo[1] = &ft_echo;
	//foo[2] = &ft_setenv;
	//foo[3] = &ft_unsetenv;
	//foo[4] = &ft_env;
	foo[5] = &ft_pwd;
	(*foo[functype])(myenv);
}

void	execfunc(t_myenv *myenv){
	
}