/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:21:41 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/03 22:05:00 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_line(char *str)
{
	char	*line;
	int		len;
	int		i;

	if (!str || ft_strlen(str) == 0)
		return (NULL);
	i = -1;
	len = ft_str_line(str);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
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
		return (free(str), str = NULL, NULL);
	len = ft_strlen(str);
	lgth = len - size;
	if (lgth <= 0)
		return (free(str), str = NULL, NULL);
	rest = malloc(sizeof(char) * (lgth + 1));
	if (!rest)
		return (free(str), str = NULL, NULL);
	while (++i < lgth && str[size + i])
		rest[i] = str[size + i];
	rest[i] = '\0';
	free(str);
	return (rest);
}

char	*ft_read_all(int fd, char *str)
{
	char	*buffer;
	int		readed;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(str), free(buffer), NULL);
		buffer[readed] = '\0';
		if (readed == 0)
			break ;
		str = ft_strjoin(str, buffer);
		if (find_line(str))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_all(fd, str);
	if (!str)
		return (NULL);
	line = get_the_line(str);
	str = get_the_rest(str, (ft_strlen(line) + 1));
	return (line);
}
