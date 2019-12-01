/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:22:40 by hboudhir          #+#    #+#             */
/*   Updated: 2019/11/30 21:19:51 by hboudhir         ###   ########.fr       */
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