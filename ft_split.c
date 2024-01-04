/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:20:57 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/03 23:18:30 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			continue ;
		}
		count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static	char	**ft_fill_str(char **str, char const *s, char c)
{
	int	i;
	int	pos;
	int	calc;

	i = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		calc = i;
		while (s[i] && s[i] != c)
			i++;
		str[pos] = malloc(sizeof(char) * (i - calc + 1));
		if (!str[pos])
			return (0);
		ft_strlcpy(str[pos], (s + calc), (i - calc + 1));
		pos++;
	}
	str[pos] = NULL;
	return (str);
}

void	ft_free(char **str, int len)
{
	int	i;

	(void)len;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**str;

	if (!s)
		return (0);
	words = count_words(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (0);
	if (!ft_fill_str(str, s, c))
	{
		ft_free(str, words);
		return (0);
	}
	return (str);
}
