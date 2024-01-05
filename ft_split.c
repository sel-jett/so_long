/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:20:57 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 03:45:59 by sel-jett         ###   ########.fr       */
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
		str[pos] = my_malloc((sizeof(char) * (i - calc + 1)), 1);
		ft_strlcpy(str[pos], (s + calc), (i - calc + 1));
		pos++;
	}
	str[pos] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**str;

	if (!s)
		return (0);
	words = count_words(s, c);
	str = my_malloc((sizeof(char *) * (words + 1)), 1);
	ft_fill_str(str, s, c);
	return (str);
}
