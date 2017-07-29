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
		{
			printf("found match\n");
			ret = i + 1;
		}
		printf("args[0] = %s, builtin[%d] = %s\n", args[0], i, builtin[i]);//remove
		i++;
	}
	if (ret == 0)
		ret = 5;
	printf("ret = %d\n", ret);//remove
	return (ret);
}

//int echo(int **)
void	b_launch(char **args, int i)
{
	int (*foo[5])(char *);
	foo[0] = &ft_cd;
   	(*foo[i])(args[1]);
	//foo[1] = &ft_echo;
	//foo[2] = &ft_setenv;
	//foo[3] = &ft_unsetenv;
	//foo[4] = &ft_env;


}

void	launcher(char **args)
{
	int		i;

	i = 0;
	if ((i = is_built_in(args)) < 5)
		b_launch(args, i - 1);
	else
		printf("not built_in\n");
}
