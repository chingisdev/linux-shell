/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:46:08 by ctycho            #+#    #+#             */
/*   Updated: 2021/02/17 00:07:16 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			mini_pwd(t_mini	*s)
{
	char		*s1;

	s1 = NULL;
	s1 = malloc(1000);
	getcwd(s1, 100);
	write(1, s1, ft_strlen(s1));
	write(1, "\n", 1);
	ft_memdel_1d(s1);
}