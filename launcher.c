#include "minishell.h"

int		is_built_in(char **args)
{
	int		i;
	char	*builtin[7];
	int		ret;

	builtin[0] = "cd";
	builtin[1] = "echo";
	builtin[2] = "setenv";
	builtin[3] = "unsetenv";
	builtin[4] = "env";
	builtin[5] = 0;
	i = 0;
	ret = 0;
	while (builtin[i])
	{
		if (ft_strcmp(args[0], builtin[i]))
			ret = i + 1;
		i++;
	}
	return (ret);
}

int echo(int **)
void	b_launch(char **args)
{
	int (*foo[5])(int);

	foo[0] = ft_cd; 
	foo[1] = ft_echo;
	foo[2] = ft_setenv;
	foo[3] = ft_unsetenv;
	foo[4] = ft_env;


}

void	launcher(char **args)
{
	int		i;

	i = 0;
	if (is_built_in(args))
		b_launch(args, i)
	else 
}
