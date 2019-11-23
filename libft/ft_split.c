/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:30:15 by hboudhir          #+#    #+#             */
/*   Updated: 2019/10/28 13:58:02 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_size(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int		ft_countwd(char *str, char c)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == c || str[i] == '\0')
			j = 1;
		else
		{
			if (j)
			{
				k++;
				j = 0;
			}
		}
		i++;
	}
	return (k);
}

static int		*ft_words(char *str, char c)
{
	int i;
	int *s;
	int j;
	int k;
	int z;

	s = (int*)malloc(4 * (ft_countwd(str, c) + 1));
	if (!s)
		return (NULL);
	s[0] = 0;
	k = 0;
	i = -1;
	j = 1;
	while (str[++i])
		if (str[i] != c && str[i] != '\0')
		{
			z = i - 1;
			if (i == 0 || str[z] == c)
			{
				s[++k] = i;
				s[0]++;
			}
		}
	return (s);
}

static char		**ft_hate_norme(int *z, char const *s, char c, char **div)
{
	int i;
	int j;
	int len;

	i = -1;
	while (++i < z[0])
	{
		j = -1;
		len = ft_word_size((char *)s + z[i + 1], c);
		div[i] = (char *)malloc((len + 1));
		if (!div[i])
		{
			while (div[--i])
				free(div[i]);
			free(div);
			return (NULL);
		}
		while (++j < len)
			div[i][j] = (char)s[z[i + 1] + j];
		div[i][len] = '\0';
	}
	div[i] = 0;
	return (div);
}

char			**ft_split(char const *s, char c)
{
	int		*z;
	int		i;
	char	**div;

	if (s)
	{
		i = 0;
		z = ft_words((char *)s, c);
		div = (char **)malloc(sizeof(char *) * (ft_countwd((char *)s, c) + 1));
		if (!div)
			return (NULL);
		div = ft_hate_norme(z, s, c, div);
		return (div);
	}
	return (NULL);
}
