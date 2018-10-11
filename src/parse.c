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
	else if (ft_strcmp(myenv->tokens[0], "exit") == 0)
		myenv->loop = 0; // return -1 by default for exit
	else
		ret = -2;
	return (ret);
}

void	execbuiltinfunc(t_myenv *myenv, int functype)
{
	void (*foo[6])(t_myenv *);

	foo[0] = &ft_cd;
	//foo[1] = &ft_echo;
	foo[2] = &ft_env;
	foo[3] = &ft_setenv;
	foo[4] = &ft_unsetenv;
	(*foo[functype])(myenv);
}

void	execfunc(t_myenv *myenv)
{
	char *newbinary;
	if ((newbinary = verifybinary(myenv)) != NULL)
	{
		printf("execfunc\narg0 = %s\n", myenv->tokens[0]); // debug // Check on the macs at campus
		execve(newbinary, myenv->tokens, myenv->env);
	}
	else
	{
		puts("binary inaccessible!"); // debug
	}
}

// verify binary
char	*verifybinary(t_myenv *myenv)
{
	char	**paths;
	char	*pathstr;
	char	*newbinary;
	char	*slash;
	int		i;

	pathstr = find(myenv, "PATH");
	paths = ft_strsplit(pathstr, ':');
	free(pathstr);
	i = -1;
	while (paths[++i] != NULL)
	{
		slash = ft_strjoin("/", myenv->tokens[0]);
		newbinary = ft_strjoin(paths[i], slash);
		if (access(newbinary, X_OK) == 0)
		{
			free(slash);
			return (newbinary);
		}
			free(slash);
			free(newbinary);
	}
	return (NULL);
}

// copy external env to internal inv
void	copy_env(t_myenv *myenv)
{
	extern char	**environ;
	int			j;

	j = 0;
	while(environ[myenv->envsize])
		myenv->envsize++;
	//printf("i = %d\n", myenv->envsize);// NOTE envsize is the total natural number of subarrays, including the null terminator
	myenv->env = (char**)malloc(sizeof(char*) * myenv->envsize);
	while(j < myenv->envsize - 1)
	{
		myenv->env[j] = strdup(environ[j]);
		j++;
	}
	//printf("j = %d\n", j);// NOTE j is the index of the subarrays. envsize -1 being the index of the null terminator
	myenv->env[j] = NULL;
	//free_2d_str(environ); // weird that this works while commented
}