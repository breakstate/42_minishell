/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:18:47 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/28 10:28:41 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	extern char **environ;
	int i = -1;
	while (environ[++i])
		printf("%s, i = %d\n", environ[i], i);
	environ[i] = "HEART = HOME";
	printf("i = %d--------------------------------\n", i);
	i = -1;
	while (++i < 40)
		printf("%s, i = %d\n", environ[i], i);

}
