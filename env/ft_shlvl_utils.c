/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlvl_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 05:47:18 by ctycho            #+#    #+#             */
/*   Updated: 2021/03/22 05:48:08 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int						mini_atoi(char *line)
{
	int					i;
	int					res;

	i = 0;
	res = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			res = (res * 10) + (line[i] - 48);
			i++;
		}
		else
			i++;
	}
	return (res);
}

int						check_shlvl(t_mini *s, char *line, int	sep)
{
	int					i = 0;
	int					flag = 0;

	if (sep == 0)
	{
		while (line[i] != '=')
			i++;
		i++;
		if (line[i] == '\0')
			return (2);
		while (line[i] != '\0')
		{
			if (line[i] >= '0' && line[i] <= '9')
				flag = 1;
			else
				return (2);
			i++;
		}
	}
	else if (sep == 1)
	{
		while (line[i] != '=')
			i++;
		i = i + 2;
		if (line[i + 1] == '\0')
			return (2);
		while (line[i + 1] != '\0')
		{
			if (line[i] >= '0' && line[i] <= '9')
				flag = 1;
			else
				return (2);
			i++;
		}
	}
	return (flag);
}