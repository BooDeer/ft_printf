/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:44:59 by hboudhir          #+#    #+#             */
/*   Updated: 2019/10/27 12:39:08 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	size_t				j;
	char				*ha;
	char				*ne;

	ha = (char *)haystack;
	ne = (char *)needle;
	i = 0;
	if (*needle == '\0')
		return (ha);
	if (len == 0)
		return (NULL);
	while (ha[i] != '\0' && i < len)
	{
		j = 0;
		if (ha[i] == ne[j])
		{
			while (ne[j] != '\0' && ha[i + j] == ne[j] && i + j < len)
				j++;
			if (j == ft_strlen(needle))
				return (&ha[i]);
		}
		i++;
	}
	return (NULL);
}
