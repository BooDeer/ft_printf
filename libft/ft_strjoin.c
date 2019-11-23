/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:54:04 by hboudhir          #+#    #+#             */
/*   Updated: 2019/10/22 11:58:18 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	size_t			n;
	size_t			i;

	if (s1)
	{
		i = 0;
		n = (ft_strlen(s1) + ft_strlen(s2));
		str = (char *)malloc(n + 1);
		if (!str)
			return (NULL);
		while (i < n)
		{
			if (*s1 != '\0')
				str[i] = *(char *)s1++;
			else if (*s2 != '\0')
				str[i] = *(char *)s2++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
