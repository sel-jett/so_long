/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:16:01 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 03:27:29 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_exit(void)
{
	exit(1);
}

void	ft_helper(t_maps *maps, int x, int y, int *check)
{
	if (maps->map[maps->py][maps->px] != '1')
	{
		maps->map[maps->py][maps->px] = 'P';
		maps->map[maps->exit_y][maps->exit_x] = 'E';
	}
	if (maps->c == 0 && maps->map[maps->py + (y)][maps->px + (x)] == 'E')
		ft_exit();
	if (maps->map[maps->py + (y)][maps->px + (x)] != '1' && !*check)
	{
		maps->map[maps->py][maps->px] = '0';
		maps->map[maps->exit_y][maps->exit_x] = 'E';
		maps->map[maps->py + (y)][maps->px + (x)] = 'P';
		maps->move++;
		ft_putstr_fd(ft_itoa(maps->move));
		maps->py = maps->py + (y);
		maps->px = maps->px + (x);
	}
}

void	ft_move(t_maps *m, int x, int y)
{
	int		check;

	check = 0;
	if ((m->py + (y)) < m->height && (m->px + (x)) < m->width)
	{
		if (m->map[m->py + (y)][m->px + (x)] != '1')
		{
			(m->map[m->py + (y)][m->px + (x)] == 'C') && ((m->c)--);
			if (m->c && m->py == m->exit_y && m->px == m->exit_x)
			{
				if (m->map[m->py][m->px] != '1'
					&& m->map[m->exit_y][m->exit_x] != '1')
				{
					(check = 1) && (m->map[m->py][m->px] = '0');
					m->map[m->exit_y][m->exit_x] = 'P';
					m->move++;
					ft_putstr_fd(ft_itoa(m->move));
					m->py = m->py + (y);
					m->px = m->px + (x);
				}
			}
			ft_helper(m, x, y, &check);
		}
		ft_draw(m);
	}
}

static int	keys_lord(int k, t_maps *map)
{
	(void)map;
	if (k == 53)
		ft_exit();
	else if (k == 126 || k == 13)
		ft_move(map, 0, -1);
	else if (k == 125 || k == 1)
		ft_move(map, 0, 1);
	else if (k == 124 || k == 2)
		ft_move(map, 1, 0);
	else if (k == 123 || k == 0)
		ft_move(map, -1, 0);
	mlx_clear_window(map->p_mlx, map->w_mlx);
	ft_draw(map);
	return (1);
}

void	ft_hook_mlx(t_maps *maps)
{
	mlx_hook(maps->w_mlx, 17, 0, ft_exit, maps);
	mlx_hook(maps->w_mlx, 2, 0, keys_lord, maps);
}
