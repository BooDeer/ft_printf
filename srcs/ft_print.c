/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:22:40 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/04 18:04:13 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *c)
{
	write(1, c, ft_strlen(c));
}

int			skip_spefix(char c, char *set)
{
	size_t i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_hexconv1(size_t c)
{
	char	*hex;
	int		i;
	int		temp;

	i = 0;
	hex = (char *)malloc(sizeof(char) * 20);
	if (!c)
		hex[0] = '0';
	while (c)
	{
		temp = c % 16;
		if (temp < 10)
		{
			hex[i] = temp + 48;
			i++;
		}
		else
		{
			hex[i] = temp + 87;
			i++;
		}
		c /= 16;
	}
	hex = ft_strrev(hex);
	return (hex);
}

int			precision_exist(t_list *node, int i)
{
	i--;
	while (node->flag[i] != '%' && node->flag[i])
	{
		if (node->flag[i] == '.')
			return (1);
		i--;
	}
	return (0);
}
