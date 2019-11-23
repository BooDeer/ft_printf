/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:27:40 by hboudhir          #+#    #+#             */
/*   Updated: 2019/10/20 16:32:06 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*found;
	size_t		max;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	max = ft_strlen(s);
	found = (char *)s;
	if (max == 0 && *found != (char)c)
		return (NULL);
	while (i <= max)
	{
		if (found[i] == (char)c)
			j = i;
		i++;
	}
	if (found[j] == (char)c)
		return (&found[j]);
	return (NULL);
}
