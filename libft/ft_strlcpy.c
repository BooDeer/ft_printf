/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:56:57 by hboudhir          #+#    #+#             */
/*   Updated: 2019/10/22 15:47:38 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	char		*e;
	const char	*s;

	if (dst)
	{
		d = dst;
		e = dst + size;
		s = src;
		while (*s != '\0' && d < e)
			*d++ = *s++;
		if (d < e)
			*d = 0;
		else if (size > 0)
			d[-1] = 0;
		while (*s != '\0')
			s++;
		return (s - src);
	}
	return (0);
}
