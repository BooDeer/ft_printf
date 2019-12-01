/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:17:41 by hboudhir          #+#    #+#             */
/*   Updated: 2019/11/30 21:18:54 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_forbidden(char c, char *set)
{
	size_t i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	first_index(char *s1, char *set)
{
	size_t i;

	i = 0;
	while (is_forbidden(s1[i], set))
		i++;
	return (i);
}

static int	last_index(char *s1, char *set)
{
	size_t len;

	len = ft_strlen(s1) - 1;
	while (is_forbidden(s1[len], set))
		len--;
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	char		*ban;
	size_t		start;
	size_t		len;
	size_t		end;

	if (s1)
	{
		str = (char *)s1;
		ban = (char *)set;
		len = ft_strlen(s1);
		start = first_index(str, ban);
		if (start == len)
			return (ft_strdup(""));
		end = last_index(str, ban);
		return (ft_substr(str, start, end - start + 1));
	}
	return (NULL);
}
