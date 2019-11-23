/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:20:35 by hboudhir          #+#    #+#             */
/*   Updated: 2019/10/28 13:57:42 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_memrcpy(void *dst, const void *src, size_t n)
{
	char				*d;
	const char			*s;
	size_t				i;

	d = (char *)dst;
	s = (const char *)src;
	i = n - 1;
	while (n--)
	{
		*(d + i) = *(s + i);
		i--;
	}
	return (d);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char					*d;
	const char				*s;

	d = (char *)dst;
	s = (const char *)src;
	if (len == 0 || (dst == NULL && src == NULL))
		return (dst);
	if (!ft_strncmp(d, s, len))
		return (dst);
	if (d < s)
		ft_memcpy(d, s, len);
	else
		ft_memrcpy(d, s, len);
	return (d);
}
