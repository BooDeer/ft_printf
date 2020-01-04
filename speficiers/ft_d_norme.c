/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_norme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 03:07:11 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/04 18:05:04 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

int		ft_d_specifier01(t_printf *d, va_list args, t_list *node, int i)
{
	int	len;

	while (node->flag[i] == '-' || node->flag[i] == '0')
		d->flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		d->width = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(d->width) < 0)
		{
			d->width++;
			d->flag = '-';
		}
		i++;
	}
	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		d->width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	return (i);
}

void	ft_d_specifier02(t_printf *d, va_list args, t_list *node, int i)
{
	int	len;

	if (node->flag[i] == '*')
	{
		d->precision = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(d->precision) < 0)
			d->precision = ft_strdup("-1");
		i++;
	}
	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		d->precision = ft_substr(node->flag, len, i - len + 1);
	if (!d->width)
		d->width = ft_strdup("0");
	if (!d->precision && node->flag[i - 1] == '.')
		d->precision = ft_strdup("0");
	else if (!d->precision)
		d->precision = ft_strdup("-1");
}

void	ft_d_specifier04(t_printf *d, int len)
{
	if (ft_atoi(d->precision) != -1 && len < 0)
		ft_memset(d->string, '0', ft_atoi(d->precision) + 1);
	else if (ft_atoi(d->precision) != -1)
		ft_memset(d->string, '0', ft_atoi(d->precision));
	if (ft_atoi(d->precision) > ft_counter(len) - 1)
	{
		if (len < 0)
		{
			len *= -1;
			d->string[0] = '-';
			ft_memcpy(&d->string[ft_atoi(d->precision) - ft_counter(len)
			+ 2], ft_itoa(len), ft_counter(len) - 1);
		}
		else
			ft_memcpy(&d->string[ft_atoi(d->precision) - ft_counter(len)
			+ 1], ft_itoa(len), ft_counter(len) - 1);
	}
	else
		ft_d_speficier_norm(d, len);
}

void	ft_d_specifier05(t_printf *d, int len)
{
	if (d->flag == '0')
		ft_memset(d->string, '0', ft_atoi(d->width));
	if (ft_atoi(d->precision) != -1)
		ft_memset(&d->string[ft_atoi(d->width) - ft_atoi(d->precision)]
		, '0', ft_atoi(d->precision));
	if (len < 0)
	{
		len *= -1;
		if (d->flag == '0')
			d->string[0] = '-';
		else if (ft_counter(len) > ft_atoi(d->precision))
			d->string[ft_atoi(d->width) - ft_counter(len)] = '-';
		else
			d->string[ft_atoi(d->width) - ft_atoi(d->precision) -
			1] = '-';
	}
	if (len == 0 && ft_atoi(d->precision) == 0)
		;
	else
		ft_memcpy(&d->string[ft_atoi(d->width) - ft_counter(len) + 1],
		ft_itoa(len),
	ft_counter(len));
}
