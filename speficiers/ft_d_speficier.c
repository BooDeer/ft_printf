/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:56 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/04 07:04:29 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int				ft_counter(int n)
{
	int count;

	count = 1;
	if (n < 0)
		count++;
	if (n == 0)
		count = 2;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void		ft_d_specifier06(t_printf *d, int len)
{
	if (len < 0)
	{
		d->precision = ft_strdup(ft_itoa(ft_atoi(d->precision) + 1));
		d->string = (char *)malloc(sizeof(char) * ft_atoi(d->precision)
		+ 1);
	}
	else
		d->string = (char *)malloc(sizeof(char) * ft_atoi(d->precision)
		+ 1);
	ft_memset(d->string, '0', ft_atoi(d->precision));
	if (len < 0)
	{
		len *= -1;
		d->string[0] = '-';
	}
	ft_strlcpy(&d->string[ft_atoi(d->precision) - ft_counter(len) + 1],
	ft_itoa(len),
	ft_counter(len));
	d->string[ft_atoi(d->precision)] = '\0';
}

static void		ft_d_specifier07(t_printf *d, int len)
{
	if (len == 0 && (ft_atoi(d->precision) == 0 || ft_atoi(d->precision)
	== 1) && ft_counter(len) == 1)
		d->string = ft_strdup("");
	else
	{
		d->string = (char *)malloc(sizeof(char) * ft_counter(len) + 1);
		d->string = ft_strdup(ft_itoa(len));
		d->string[ft_counter(len)] = '\0';
	}
}

static void		ft_d_specifier03(t_printf *d, int len)
{
	if (ft_atoi(d->width) > ft_counter(len) - 2 && ft_atoi(d->width)
	> ft_atoi(d->precision))
	{
		d->string = (char *)malloc(sizeof(char) * ft_atoi(d->width) + 1);
		ft_memset(d->string, ' ', ft_atoi(d->width));
		if ((ft_atoi(d->precision) == 0 || ft_atoi(d->precision) == 1)
		&& len == 0)
			;
		else if (d->flag == '-')
			ft_d_specifier04(d, len);
		else
			ft_d_specifier05(d, len);
		d->string[ft_atoi(d->width)] = '\0';
	}
	else if (ft_atoi(d->precision) > ft_counter(len) - 1)
		ft_d_specifier06(d, len);
	else
		ft_d_specifier07(d, len);
}

void			ft_d_specifier(va_list args, t_list *node)
{
	int			i;
	int			len;
	t_printf	*d;

	d = initializing();
	i = 0;
	if (!node)
		return ;
	i = ft_d_specifier01(d, args, node, i);
	ft_d_specifier02(d, args, node, i);
	len = va_arg(args, int);
	if (ft_atoi(d->precision) < ft_counter(len) - 1)
		if (d->flag == '0' && ft_atoi(d->precision) >= 0)
			d->flag = '\0';
	if (ft_atoi(d->precision) >= ft_counter(len) - 1)
		if (d->flag == '0')
			d->flag = '\0';
	if (ft_atoi(d->width) == 0 && ft_atoi(d->precision) == 0 &&
	(len == 0 || ft_counter(len) == 0))
		d->string = ft_strdup("");
	else
		ft_d_specifier03(d, len);
	node->str = d->string;
}
