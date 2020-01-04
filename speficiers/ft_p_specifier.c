/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:37:36 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/03 03:30:37 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

static int		ft_count1(int n)
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

static	void	ft_p_speficier03(t_printf *p, int len)
{
	p->string = (char *)malloc(sizeof(char) * ft_atoi(p->width) + 1);
	ft_memset(p->string, ' ', ft_atoi(p->width));
	if (p->flag == '-')
	{
		ft_memset(p->string, '0', len);
		if (len > (int)ft_strlen(p->precision))
			ft_memcpy(&p->string[len - ft_strlen(p->precision)],
			p->precision, ft_strlen(p->precision));
		else
			ft_memcpy(p->string, p->precision,
			ft_strlen(p->precision));
	}
	else if (p->flag == '0')
		ft_memset(p->string, '0', ft_atoi(p->width));
	else
	{
		ft_memset(&p->string[ft_atoi(p->width) - len], '0', len);
		ft_memcpy(&p->string[ft_atoi(p->width) - ft_strlen(p->precision)],
		p->precision, ft_strlen(p->precision));
	}
	p->string[ft_atoi(p->width)] = '\0';
}

static	void	ft_p_speficier04(t_printf *p, int len)
{
	if (len > (int)ft_strlen(p->precision))
	{
		p->string = (char *)malloc(sizeof(char) * len + 1);
		ft_memset(p->string, '0', len);
		ft_strlcpy(&p->string[len - ft_strlen(p->precision)], p->precision,
		ft_strlen(p->precision) + 1);
		p->string[len] = '\0';
	}
	else
		p->string = ft_strdup(p->precision);
}

static	void	ft_p_speficier05(t_printf *p, int len)
{
	if (ft_atoi(p->precision) < ft_count1(len) - 1)
		if (p->flag == '0' && ft_atoi(p->precision) >= 0)
			p->flag = '\0';
	if (ft_atoi(p->precision) >= ft_count1(len) - 1)
		if (p->flag == '0')
			p->flag = '\0';
	if (*p->precision == '0' && len)
	{
		p->precision = ft_strdup("");
		p->precision = ft_strjoin("0x", p->precision);
	}
	else
		p->precision = ft_strjoin("0x", p->precision);
}

void			ft_p_specifier(va_list args, t_list *node)
{
	int			i;
	int			len;
	t_printf	*p;

	p = initializing();
	i = 0;
	if (!node)
		return ;
	i = ft_p_speficier01(p, args, node, i);
	ft_p_speficier02(p, args, node, i);
	len = ft_atoi(p->precision);
	p->precision = ft_strdup(ft_hexconv1(va_arg(args, size_t)));
	ft_p_speficier05(p, len);
	if (ft_atoi(p->width) > (int)ft_strlen(p->precision) &&
	ft_atoi(p->width) > len)
		ft_p_speficier03(p, len);
	else
		ft_p_speficier04(p, len);
	node->str = p->string;
}
