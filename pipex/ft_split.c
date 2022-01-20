/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:49:55 by slammari          #+#    #+#             */
/*   Updated: 2022/01/20 15:32:59 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_malloc_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	count_word(char const *str, char c)
{
	size_t			count;
	size_t			i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	count_str(char const *str, char c)
{
	size_t			count;
	size_t			i;

	i = 0;
	count = 0;
	while (str[i] != c && str[i])
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**ret;
	int				j;
	int				k;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!ret)
		return (NULL);
	k = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (count_str(s, c) == 0)
			break ;
		ret[k] = (char *)malloc(sizeof(char) * (count_str(s, c) + 1)));
		if (!ret[k])
			return (ft_malloc_free(ret));
		while (*s && *s != c)
			ret[k][j++] = *s++;
		ret[k++][j] = '\0';
	}
	ret[k] = NULL;
	return (ret);
}
