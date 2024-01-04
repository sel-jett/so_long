/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:18:40 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/04 02:07:13 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_copy(t_maps *map)
{
	char	**cpy;
	int		i;

	i = -1;
	cpy = my_malloc((sizeof(char *) * (map->height + 1)), 1);
	while (++i < map->height)
	{
		cpy[i] = my_malloc((map->width + 1), 1);
		ft_strcpy(cpy[i], map->map[i]);
	}
	cpy[i] = NULL;
	return (cpy);
}


static void	flood_fill(t_maps *map, char **cpy, int i, int j)
{
	// int	k = 0;
	// int	s = 0;
	// while (map->map[k])
	// {
	// 	s = 0;
	// 	while (map->map[k][s])
	// 		printf("%c", map->map[k][s++]);
	// 	puts("");
	// 	k++;
	// }
	// exit(1);
	if (i < 0 || j < 0 || j >= map->width || i >= map->height \
		 || cpy[i][j] == 'z' || cpy[i][j] == '1')
		return ;
	cpy[i][j] = 'z';
	flood_fill(map, cpy, i + 1, j);
	flood_fill(map, cpy, i - 1, j);
	flood_fill(map, cpy, i, j + 1);
	flood_fill(map, cpy, i, j - 1);
}

static int	check_flood(char **cpy)
{
	int	i;
	int	j;

	i = 0;
	while (cpy[i])
	{
		j = 0;
		while (cpy[i][j])
		{
			if (cpy[i][j] == 'C' || cpy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	puts("9alwa");
	return (1);
}

int	valid_flood(t_maps *map)
{
	char	**cpy;

	cpy = map_copy(map);
	// printf("%d >>>> %d\n", map->py, map->px);
	flood_fill(map, cpy, map->py, map->px);
	// exit(1);
	if (!check_flood(cpy))
		return (0);
	return (1);
}
