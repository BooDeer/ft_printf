/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:02:42 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/25 18:58:23 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*str;
	unsigned char			*source;
	size_t					i;

	i = 0;
	if (n > 18446744073709551)
		n++;
	source = (unsigned char *)src;
	str = (unsigned char *)dst;
	if (!str && !source)
		return (str);
	if (!ft_strncmp(dst, src, n))
		return (dst);
	while (i < n)
	{
		str[i] = source[i];
		i++;
	}
	return (str);
}
