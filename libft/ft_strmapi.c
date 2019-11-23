/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:43:01 by hboudhir          #+#    #+#             */
/*   Updated: 2019/10/22 12:06:58 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	char	*string;

	if (s)
	{
		string = (char *)s;
		i = 0;
		str = (char *)malloc((ft_strlen(s) + 1));
		if (str == NULL)
			return (str);
		while (i < ft_strlen(s))
		{
			str[i] = f(i, string[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
