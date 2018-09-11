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
	else
		ret = -2;
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
	extern char **environ;


	execve("/bin/ls", myenv->tokens, environ);
}
/*
// get 2d array of possible paths
void	strip_paths(t_myenv *myenv)
{
	
}
*/
// copy external env to internal inv
void	copy_env(t_myenv *myenv)
{
	extern char	**environ;
	int			envsize;
	int			j;

	j = 0;
	envsize = 0;
	while(environ[envsize])
		envsize++;
	printf("i = %d\n", envsize);
	myenv->env = (char**)malloc(sizeof(char*) * envsize);
	while(j < envsize - 1)
	{
		myenv->env[j] = strdup(environ[j]);
		j++;
	}
	printf("j = %d\n", j);
	myenv->env[j] = NULL;
	// execve test
	
	j = 0;
	char **line;
	while (myenv->env[j] != NULL)
	{
		line = ft_strsplit("ls -1", ' ');
		if (ft_strcmp(line[0], "PATH") == 0)
		{
			printf("myenv->env[i]= %s\n", myenv->env[j]);
			break;
		}
		j++;
	}
	int val = access("/bin/ls", R_OK);
	//execve("/bin/ls", line, myenv->env);
	
}








/*
	while (*myenv->env != NULL)
	{
		printf("freeing %s\n", *myenv->env);
		free(*myenv->env++);
	}*/
	/* test/debug below
	while (*myenv->env != NULL)
	{
		printf("Mine: %s\n", *myenv->env);
		*myenv->env++;
	}
}


	int	i;

	i = 0;
	while (*array != NULL)
	{
		printf("**array =%s\n", *array);
		free(*array);
		printf("i = %d\n", i);
		i++;
	}
	*/