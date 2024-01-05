/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:29:42 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 04:19:14 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_map(t_maps *maps)
{
	maps->map = NULL;
	maps->p = 0;
	maps->px = 0;
	maps->py = 0;
	maps->c = 0;
	maps->exit = 0;
	maps->exit_x = 0;
	maps->exit_y = 0;
	maps->width = 0;
	maps->height = 0;
	maps->move = 0;
}

int	main(int ac, char **av)
{
	t_maps	*maps;
	int		i;

	i = 0;
	ft_check_args(ac, av);
	maps = my_malloc(sizeof(t_maps), 1);
	ft_init_map(maps);
	maps->map = ft_split(ft_check_map(av[1], maps), '\n');
	if (!valid_flood(maps))
		my_malloc(0, 0);
	ft_mlx(maps);
}
