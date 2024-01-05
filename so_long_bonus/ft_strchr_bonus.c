/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:43:57 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 03:27:29 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_strchr(const char *s, t_maps *maps)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'P')
		{
			(maps->p)++;
			maps->px = i;
			maps->py = maps->height;
		}
		else if (s[i] == 'E')
		{
			(maps->exit)++;
			maps->exit_x = i;
			maps->exit_y = maps->height;
		}
		else if (s[i] == 'C')
			(maps->c)++;
		else if (s[i] != '1' && s[i] != '0')
			exit(1)
		i++;
	}
}
