/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:21:41 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 04:26:10 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_the_line(char *str)
{
	char	*line;
	int		len;
	int		i;

	if (!str || ft_strlen(str) == 0)
		return (NULL);
	i = -1;
	len = ft_str_line(str);
	line = my_malloc((sizeof(char) * (len + 1)), 1);
	while (++i < len && str[i])
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

char	*get_the_rest(char *str, size_t size)
{
	char	*rest;
	size_t	len;
	int		lgth;
	int		i;

	i = -1;
	if (!str || ft_strlen(str) <= 0)
		return (NULL);
	len = ft_strlen(str);
	lgth = len - size;
	if (lgth <= 0)
		return (NULL);
	rest = my_malloc((sizeof(char) * (lgth + 1)), 1);
	while (++i < lgth && str[size + i])
		rest[i] = str[size + i];
	rest[i] = '\0';
	return (rest);
}

char	*ft_read_all(int fd, char *str)
{
	char	*buffer;
	int		readed;

	buffer = my_malloc((sizeof(char) * (BUFFER_SIZE + 1)), 1);
	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			my_malloc(0, 0);
		buffer[readed] = '\0';
		if (readed == 0)
			break ;
		str = ft_strjoin(str, buffer);
		if (find_line(str))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		my_malloc(0, 0);
	str = ft_read_all(fd, str);
	if (!str)
		return (NULL);
	line = get_the_line(str);
	str = get_the_rest(str, (ft_strlen(line) + 1));
	return (line);
}
