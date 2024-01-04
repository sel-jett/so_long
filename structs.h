/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:37:44 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/03 23:20:36 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_data
{
	void			*data;
	struct s_data	*next;
}	t_data;

typedef struct s_schr
{
	char	**map;
	int		p;
	int		px;
	int		py;
	int		c;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		width;
	int		height;
}	t_maps;
