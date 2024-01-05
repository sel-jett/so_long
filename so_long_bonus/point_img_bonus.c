/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_img_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:06:44 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 03:48:52 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_path(t_maps *map)
{
	int		i;
	char	*path[10];
	int		n;
	int		m;

	i = -1;
	path[0] = "img/black.xpm";
	path[1] = "img/close.xpm";
	path[2] = "img/eth.xpm";
	path[3] = "img/open.xpm";
	path[4] = "img/player.xpm";
	path[5] = "img/wall.xpm";
	path[6] = "img/enemy_1.xpm";
	path[7] = "img/enemy_2.xpm";
	path[8] = "img/enemy_3.xpm";
	path[9] = "img/enemy_4.xpm";
	while (++i < 10)
	{
		map->arr[i] = mlx_xpm_file_to_image(map->p_mlx, path[i], &n, &m);
		if (!map->arr[i] || n > 50 || m > 50)
			exit(1);
	}
}

static void	my_helper(t_maps *m, int i, int j)
{
	if (m->map[i][j] == '0')
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[0], j * 50, i * 50);
	else if (m->map[i][j] == '1')
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[5], j * 50, i * 50);
	else if (m->map[i][j] == 'P')
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[4], j * 50, i * 50);
	else if (m->map[i][j] == 'E' && m->c > 0)
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[1], j * 50, i * 50);
	else if (m->map[i][j] == 'E' && m->c == 0)
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[3], j * 50, i * 50);
	else if (m->map[i][j] == 'C')
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[2], j * 50, i * 50);
}

void	ft_draw(t_maps *m)
{
	int		i;
	int		j;
	char	*line;

	get_path(m);
	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			my_helper(m, i, j);
			j++;
		}
		i++;
	}
	draw_enemy(m);
	if (m->enemy_x == m->py && m->enemy_y == m->px)
		my_malloc(0, 0);
	line = ft_itoa(m->move);
	i = mlx_string_put(m->p_mlx, m->w_mlx, 10, 10, 0xFFF933, line);
	if (i == -1)
		my_malloc(0, 0);
}
