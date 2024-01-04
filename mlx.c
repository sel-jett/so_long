/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:18:13 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/04 06:49:22 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_srch_place(t_maps *maps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (maps->map[i])
	{
		j = 0;
		while (maps->map[i][j])
		{
			if (maps->map[i][j] == '0' && maps->map[i + 1][j] == '0' && maps->map[i + 2][j] == '0')
			{
				maps->enemy_x = j;
				maps->enemy_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	draw_enemy(t_maps *map)
{
	ft_srch_place(map);
	printf("%d, %d\n", map->enemy_x, map->enemy_y);
}

void	ft_mlx(t_maps *map)
{
	map->p_mlx = mlx_init();
	map->w_mlx = mlx_new_window(map->p_mlx, (map->width * 50), ((map->height + 1) * 50), "TopG l9wada");
	ft_draw(map);
	// draw_enemy(map);
	ft_hook_mlx(map);
	mlx_loop(map->p_mlx);
}
