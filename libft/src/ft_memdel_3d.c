/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:58:39 by ctycho            #+#    #+#             */
/*   Updated: 2021/02/17 00:01:17 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memdel_3d(void ***s)
{
	int		i;
	int		j;

	i = 0;
	if (s)
	{
		while (s[i] != NULL)
		{
			j = 0;
			while (s[i][j] != NULL)
			{
				free(s[i][j]);
				j++;
			}
			free(s[i]);
			i++;
		}
	}
	free(s);
}