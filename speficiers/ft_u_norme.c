/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_norme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 03:11:09 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/03 03:17:00 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

int			ft_u_speficier01(t_printf *u, va_list args, t_list *node, int i)
{
	int		len;

	while (node->flag[i] == '-' || node->flag[i] == '0')
		u->flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		u->width = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(u->width) < 0)
		{
			u->width++;
			u->flag = '-';
		}
		i++;
	}
	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		u->width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	return (i);
}

void		ft_u_speficier02(t_printf *u, va_list args, t_list *node, int i)
{
	int	len;

	if (node->flag[i] == '*')
	{
		u->precision = ft_strdup(ft_itoa(va_arg(args, unsigned int)));
		if (ft_atoi(u->precision) < 0)
			u->precision = ft_strdup("-1");
		i++;
	}
	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		u->precision = ft_substr(node->flag, len, i - len + 1);
	if (!u->width)
		u->width = ft_strdup("0");
	if (!u->precision && precision_exist(node, i))
		u->precision = ft_strdup("0");
	else if (!u->precision)
		u->precision = ft_strdup("-1");
}

void		ft_u_speficier031(t_printf *u, int len)
{
	if (ft_atoi(u->precision) != -1)
		ft_memset(u->string, '0', ft_atoi1(u->precision));
	if (ft_atoi(u->precision) > ft_count(len))
		ft_memcpy(&u->string[ft_atoi1(u->precision) - ft_count(len) + 1],
		ft_itoa1(len), ft_count(len) - 1);
	else
		ft_memcpy(u->string, ft_itoa1(len), ft_count(len) - 1);
}

void		ft_u_speficier03(t_printf *u, int len)
{
	u->string = (char *)malloc(sizeof(char) * ft_atoi1(u->width) + 1);
	if (u->flag == '0')
		ft_memset(u->string, '0', ft_atoi1(u->width));
	else
		ft_memset(u->string, ' ', ft_atoi1(u->width));
	if (ft_atoi1(u->precision) == 0 && len == 0)
		;
	else if (u->flag == '-')
		ft_u_speficier031(u, len);
	else
	{
		if (ft_atoi(u->precision) != -1)
			ft_memset(&u->string[ft_atoi1(u->width) - ft_atoi1(u->precision)],
			'0', ft_atoi1(u->precision));
		if (len == 0 && ft_atoi1(u->precision) == 0)
			;
		else
			ft_memcpy(&u->string[ft_atoi1(u->width) - ft_count(len) + 1]
			, ft_itoa1(len),
		ft_count(len));
	}
}

void		ft_u_speficier041(t_printf *u, int len)
{
	u->string = (char *)malloc(sizeof(char) * ft_atoi1(u->precision)
	+ 1);
	ft_memset(u->string, '0', ft_atoi1(u->precision));
	ft_strlcpy(&u->string[ft_atoi1(u->precision) - ft_count(len) + 1],
	ft_itoa1(len),
	ft_count(len));
	u->string[ft_atoi1(u->precision)] = '\0';
}
