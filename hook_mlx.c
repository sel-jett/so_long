/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:16:01 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/04 06:50:26 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_exit()
{
	exit(1);
}

// static void	count_coin(t_maps *maps)
// {
// 	int	i;
// 	int	j;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (maps->map[i])
// 	{
// 		j = 0;
// 		while (maps->map[i][j])
// 		{
// 			if (maps->map[i][j] == 'C')
// 				count++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	maps->c = count;
// }

void	ft_move(t_maps *maps, int x, int y)
{
	int		check;

	check = 0;
	if ((maps->py + (y)) < maps->height && (maps->px + (x)) < maps->width)
	{
		if (maps->map[maps->py + (y)][maps->px + (x)] != '1')
		{
			if (maps->map[maps->py + (y)][maps->px + (x)] == 'C')
				(maps->c)--;
			if (maps->c && maps->py == maps->exit_y &&  maps->px == maps->exit_x)
			{
				if (maps->map[maps->py][maps->px] != '1' && maps->map[maps->exit_y][maps->exit_x] != '1')
				{
					check = 1;
					maps->map[maps->py][maps->px] = '0';
					maps->map[maps->exit_y][maps->exit_x] = 'P';
					maps->move++;
					printf("%d\n", maps->move);
					maps->py = maps->py + (y);
					maps->px = maps->px + (x);
				}
			}
			if (maps->map[maps->py][maps->px] != '1')
			{
				maps->map[maps->py][maps->px] = 'P';
				maps->map[maps->exit_y][maps->exit_x] = 'E';
			}
			if (maps->c == 0 && maps->map[maps->py + (y)][maps->px + (x)] == 'E')
				ft_exit();
			if (maps->map[maps->py + (y)][maps->px + (x)] != '1' && !check)
			{
				maps->map[maps->py][maps->px] = '0';
				maps->map[maps->exit_y][maps->exit_x] = 'E';
				maps->map[maps->py + (y)][maps->px + (x)] = 'P';
				maps->move++;
				printf("%d\n", maps->move);
				maps->py = maps->py + (y);
				maps->px = maps->px + (x);
			}
		}
		ft_draw(maps);
	}
}

static int	keys_lord(int	k, t_maps *map)
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
