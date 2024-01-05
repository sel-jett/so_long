/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:18:13 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 03:27:30 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_srch_place(t_maps *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if ((m->map[i][j] == '0' || m->map[i][j] == 'P')
				&& (m->map[i][j + 1] == '0' || m->map[i][j + 1] == 'P'))
			{
				m->enemy_x = i;
				m->enemy_y = j;
			}
			j++;
		}
		i++;
	}
}

int	affiche(t_maps *m)
{
	static int	check;
	int			y;
	int			x;

	x = m->enemy_x;
	y = m->enemy_y;
	if (check < 20)
	{
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[6], y * 50, x * 50);
		check++;
	}
	else if (check < 40)
	{
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[7], y * 50, x * 50);
		check++;
	}
	else if (check < 60 && check++)
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[8], y * 50, x * 50);
	else if (check < 70)
	{
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[9], y * 50, x * 50);
		check = 0;
	}
	return (1);
}

void	draw_enemy(t_maps *map)
{
	int	i;

	i = -1;
	ft_srch_place(map);
	mlx_loop_hook(map->p_mlx, affiche, map);
}

void	ft_mlx(t_maps *m)
{
	int	h;
	int	w;

	h = m->height;
	w = m->width;
	m->p_mlx = mlx_init();
	if (!m->p_mlx)
		exit(1)
	m->w_mlx = mlx_new_window(m->p_mlx, (w * 50), ((h + 1) * 50), "so_long");
	if (!m->w_mlx)
		exit(1)
	ft_draw(m);
	ft_hook_mlx(m);
	mlx_loop(m->p_mlx);
}
