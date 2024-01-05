/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:31:52 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 01:53:35 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_error(char *line, int mode)
{
	if (mode == 1)
		write(2, "borders error\n", 14);
	else
		write(2, "Ivalid input\n", 13);
	free(line);
	exit(1);
}

int	ft_checker(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_search(char *str)
{
	char	ptr[5];
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	ptr[0] = '.';
	ptr[1] = 'b';
	ptr[2] = 'e';
	ptr[3] = 'r';
	ptr[4] = '\0';
	while (str[i])
	{
		if (str[i] == '.')
		{
			j = i;
			while (str[j] && ptr[k] && str[j] == ptr[k])
				(j++) && (k++);
			if (k == 4 && !str[j])
				return (1);
		}
		i++;
	}
	return (0);
}

static void	ft_helper(t_maps *maps, int fd, char *line, int *line1)
{
	int	check;
	int	line2;

	while (line)
	{
		check = ft_checker(line);
		ft_strchr(line, maps);
		line = get_next_line(fd);
		line2 = ft_countt(line);
		if (line2 == 0 && !check)
			(1) && (write(2, "borders error\n", 14), free(line), exit(1), 0);
		else if (line && *line == '\0')
			(1) && (write(2, "borders error\n", 14), free(line), exit(1), 0);
		else if (!line2)
			return ;
		(maps->height)++;
		(line[*line1 - 1] != '1') && (ft_error(line, 1), 0);
		(line[0] != '1') && (ft_error(line, 1), 0);
		(*line1 != line2) && (ft_error(line, 0), 0);
	}
}

char	*ft_check_map(char *av, t_maps *maps)
{
	char	*line;
	int		fd;
	int		line1;
	char	*parser;

	fd = open(av, O_RDONLY);
	(fd < 0) && (write(2, "File doesn't exist\n", 19), my_malloc(0, 0), 0);
	line = get_next_line(fd);
	(!line) && (write(2, "Empty File\n", 11), my_malloc(0, 0), 0);
	if (!ft_checker(line))
		(1) && (write(2, "borders error\n", 14), free(line), exit(1), 0);
	line1 = ft_countt(line);
	maps->width = line1;
	ft_helper(maps, fd, line, &line1);
	free(line);
	close(fd);
	if (maps->p != 1 || maps->exit != 1 || maps->c < 1)
		my_malloc(0, 0);
	parser = ft_parser(av);
	return (parser);
}
