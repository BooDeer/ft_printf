/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 03:14:22 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/03 03:17:26 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

char			*print_number(char *number, size_t len, unsigned int nb)
{
	number[--len] = '\0';
	while (nb != '\0' && len > 0)
	{
		number[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (number);
}

void			ft_u_speficier04(t_printf *u, int len)
{
	if (ft_atoi(u->width) > ft_count(len) - 2 && ft_atoi(u->width) >
	ft_atoi(u->precision))
	{
		ft_u_speficier03(u, len);
		u->string[ft_atoi1(u->width)] = '\0';
	}
	else if (ft_atoi(u->precision) > ft_count(len))
		ft_u_speficier041(u, len);
	else
	{
		if (len == 0 && (ft_atoi1(u->precision) == 0 || ft_atoi1(u->precision)
		== 1) && ft_count(len) == 1)
			u->string = ft_strdup("");
		else
		{
			u->string = (char *)malloc(sizeof(char) * ft_count(len) + 1);
			u->string = ft_strdup(ft_itoa1(len));
			u->string[ft_count(len)] = '\0';
		}
	}
}
