/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:25:25 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/06 01:03:30 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <mlx.h>
# include "structs.h"

void	*my_malloc(size_t size, int mode);
char	*ft_itoa(int n);
void	ft_error_zero(void);
void	ft_putstr_fd(char *s);
void	ft_check_args(int ac, char **av);
char	*ft_check_map(char *av, t_maps *maps);
void	ft_strchr(const char *s, t_maps *maps);
void	ft_hook_mlx(t_maps *maps);
char	*ft_parser(char *av);
int		ft_countt(char *line);
void	ft_check_args(int ac, char **av);
int		ft_search(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
void	ft_mlx(t_maps *map);
void	draw_enemy(t_maps *map);
void	ft_draw(t_maps *maps);
void	ft_strcpy(char *dest, char *src);
int		valid_flood(t_maps *map);

#endif
