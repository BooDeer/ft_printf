/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:56 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/03 01:47:12 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

static int		ft_count(int n)
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

static	int		ft_norme01(t_printf *d, va_list args, t_list *node, int i)
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

static	void	ft_norme02(t_printf *d, va_list args, t_list *node, int i)
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

static	void	ft_norme04(t_printf *d, int len)
{
	if ((ft_atoi(d->precision) == 0 || ft_atoi(d->precision) == 1)
	&& len == 0)
		;
	else if (d->flag == '-')
	{
		if (ft_atoi(d->precision) != -1)
			ft_memset(d->string, '0', ft_atoi(d->precision));
		if (ft_atoi(d->precision) > ft_count(len) - 1)
		{
			if (len < 0)
			{
				len *= -1;
				d->string[0] = '-';
				ft_memcpy(&d->string[ft_atoi(d->precision) - ft_count(len)
				+ 2], ft_itoa(len), ft_count(len) - 1);
			}
			else
				ft_memcpy(&d->string[ft_atoi(d->precision) - ft_count(len)
				+ 1], ft_itoa(len), ft_count(len) - 1);
		}
		else
			ft_memcpy(d->string, ft_itoa(len), ft_count(len) - 1);
	}
}

static void		ft_norme05(t_printf *d, int len)
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
		else if (ft_count(len) > ft_atoi(d->precision))
			d->string[ft_atoi(d->width) - ft_count(len)] = '-';
		else
			d->string[ft_atoi(d->width) - ft_atoi(d->precision) -
			1] = '-';
	}
	if (len == 0 && ft_atoi(d->precision) == 0)
		;
	else
		ft_memcpy(&d->string[ft_atoi(d->width) - ft_count(len) + 1],
		ft_itoa(len),
	ft_count(len));
}

static void		ft_norme06(t_printf *d, int len)
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
	ft_strlcpy(&d->string[ft_atoi(d->precision) - ft_count(len) + 1],
	ft_itoa(len),
	ft_count(len));
	d->string[ft_atoi(d->precision)] = '\0';
}

static void		ft_norme07(t_printf *d, int len)
{
	if (len == 0 && (ft_atoi(d->precision) == 0 || ft_atoi(d->precision)
	== 1) && ft_count(len) == 1)
		d->string = ft_strdup("");
	else
	{
		d->string = (char *)malloc(sizeof(char) * ft_count(len) + 1);
		d->string = ft_strdup(ft_itoa(len));
		d->string[ft_count(len)] = '\0';
	}
}

static void		ft_norme03(t_printf *d, int len)
{
	if (ft_atoi(d->width) > ft_count(len) - 2 && ft_atoi(d->width)
	> ft_atoi(d->precision))
	{
		d->string = (char *)malloc(sizeof(char) * ft_atoi(d->width) + 1);
		ft_memset(d->string, ' ', ft_atoi(d->width));
		if ((ft_atoi(d->precision) == 0 || ft_atoi(d->precision) == 1)
		&& len == 0)
			;
		else if (d->flag == '-')
			ft_norme04(d, len);
		else
			ft_norme05(d, len);
		d->string[ft_atoi(d->width)] = '\0';
	}
	else if (ft_atoi(d->precision) > ft_count(len) - 1)
		ft_norme06(d, len);
	else
		ft_norme07(d, len);
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
	i = ft_norme01(d, args, node, i);
	ft_norme02(d, args, node, i);
	len = va_arg(args, int);
	 if (ft_atoi(d->precision) < ft_count(len) - 1)
	 	if (d->flag == '0' && ft_atoi(d->precision) >= 0)
	 		d->flag = '\0';
	if (ft_atoi(d->precision) >= ft_count(len) - 1)
		if (d->flag == '0')
			d->flag = '\0';
	if (ft_atoi(d->width) == 0 && ft_atoi(d->precision) == 0 &&
	(len == 0 || ft_count(len) == 0))
		d->string = ft_strdup("");
	else
		ft_norme03(d, len);
	node->str = d->string;
}
