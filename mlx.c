/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:18:13 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 03:27:25 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx(t_maps *m)
{
	int	h;
	int	w;

	h = m->height;
	w = m->width;
	m->p_mlx = mlx_init();
	if (!m->p_mlx)
		exit(1);
	m->w_mlx = mlx_new_window(m->p_mlx, (w * 50), ((h + 1) * 50), "so_long");
	if (!m->w_mlx)
		exit(1);
	ft_draw(m);
	ft_hook_mlx(m);
	if (mlx_loop(m->p_mlx) == -1)
		exit(1);
}
