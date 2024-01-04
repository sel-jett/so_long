/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:09:21 by sel-jett          #+#    #+#             */
/*   Updated: 2023/11/15 20:51:34 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *str);
char	*my_strcpy(char *s1, char *s2, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_all(int fd, char *str);
char	*get_next_line(int fd);
int		find_line(char *str);
char	*get_the_line(char *str);
char	*get_the_rest(char *str, size_t size);
int		ft_str_line(char *str);

#endif
