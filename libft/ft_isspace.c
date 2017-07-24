/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 12:41:33 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/11 12:52:48 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' || 
		c == '\n' || c == ' ')
		return (1);
	else
		return (0);
}