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
		if ((ft_strcmp(args[0], builtin[i]) == 0))
			ret = i + 1;
		i++;
	}
	if (ret == 0)
		ret = 5;
	return (ret);
}

void	b_launch(t_pack *pack, int i)
{
	int (*foo[5])(t_pack *);

	foo[0] = &ft_cd;
	foo[1] = &ft_echo;
	//foo[2] = &ft_setenv;
	//foo[3] = &ft_unsetenv;
	//foo[4] = &ft_env;
   	(*foo[i])(pack);
}

void	launcher(t_pack *pack)
{
	int		i;

	i = 0;
	if ((i = is_built_in(pack->args)) < 5)
		b_launch(pack, i - 1);
	//else---
		//printf("not built_in\n");---
}
