/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:06:44 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/04 06:50:16 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_path(t_maps *map)
{
	int		i;
	char	*path[6];
	int		n;
	int		m;


	i = -1;
	path[0] = "img/black.xpm";
	path[1] = "img/close.xpm";
	path[2] = "img/eth.xpm";
	path[3] = "img/open.xpm";
	path[4] = "img/player.xpm";
	path[5] = "img/wall.xpm";
	while (++i < 6)
	{
		map->arr[i] = mlx_xpm_file_to_image(map->p_mlx, path[i], &n, &m);
		if (!map->arr[i] || n > 50 || m > 50)
			my_malloc(0, 0);
	}
}

void	ft_draw(t_maps *maps)
{
	int	i;
	int	j;
	char	*line;

	get_path(maps);
	i = 0;
	while (maps->map[i])
	{
		j = 0;
		while (maps->map[i][j])
		{
			if (maps->map[i][j] == '0')
				mlx_put_image_to_window(maps->p_mlx, maps->w_mlx, maps->arr[0], (j * 50), (i * 50));
			else if (maps->map[i][j] == '1')
				mlx_put_image_to_window(maps->p_mlx, maps->w_mlx, maps->arr[5], (j * 50), (i * 50));
			else if (maps->map[i][j] == 'P')
				mlx_put_image_to_window(maps->p_mlx, maps->w_mlx, maps->arr[4], (j * 50), (i * 50));
			else if (maps->map[i][j] == 'E' && maps->c > 0)
				mlx_put_image_to_window(maps->p_mlx, maps->w_mlx, maps->arr[1], (j * 50), (i * 50));
			else if (maps->map[i][j] == 'E' && maps->c == 0)
				mlx_put_image_to_window(maps->p_mlx, maps->w_mlx, maps->arr[3], (j * 50), (i * 50));
			else if (maps->map[i][j] == 'C')
				mlx_put_image_to_window(maps->p_mlx, maps->w_mlx, maps->arr[2], (j * 50), (i * 50));
			j++;
		}
		i++;
	}
	line = ft_itoa(maps->move);
	mlx_string_put(maps->p_mlx, maps->w_mlx, 10, 10, 0xFFF933, line);
	free(line);
}

