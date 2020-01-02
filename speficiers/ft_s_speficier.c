/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:04:21 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/02 15:29:32 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int				precision_exist(t_list *node, int i)
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

static	int		ft_norme010(t_printf *s, va_list args, t_list *node, int i)
{
	int		len;

	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		s->width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	if (node->flag[i] == '*')
	{
		s->precision = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(s->precision) < 0)
			s->precision = ft_strdup("-2");
		i++;
	}
	return (i);
}

static	int		ft_norme01(t_printf *s, va_list args, t_list *node, int i)
{
	while (node->flag[i] == '-' || node->flag[i] == '0')
		s->flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		s->width = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(s->width) < 0)
		{
			s->width++;
			s->flag = '-';
		}
		i++;
	}
	return (ft_norme010(s, args, node, i));
}

static	void	ft_norme02(t_printf *s, t_list *node, int i)
{
	int len;

	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		s->precision = ft_substr(node->flag, len, i - len + 1);
	if (!s->width)
		s->width = ft_strdup("0");
	if (!s->precision && node->flag[i] == '.')
		s->precision = ft_strdup("0");
	else if (!s->precision)
		s->precision = ft_strdup("0");
}

static void		ft_norme03(t_printf *s)
{
	if (ft_atoi(s->width) > (int)ft_strlen(s->precision))
	{
		s->string = (char *)malloc(sizeof(char) * ft_atoi(s->width) + 1);
		ft_memset(s->string, ' ', ft_atoi(s->width));
		if (ft_strlen(s->precision))
		{
			if (s->flag == '-')
				ft_memmove(s->string, s->precision, ft_strlen(s->precision));
			else
				ft_strlcpy(&s->string[ft_atoi(s->width) - ft_strlen(s->
				precision)], s->precision, ft_strlen(s->precision) + 1);
			s->string[ft_atoi(s->width)] = '\0';
		}
		else if (ft_atoi(s->width) == 1)
			s->string[ft_atoi(s->width)] = '\0';
	}
	else
		s->string = ft_strdup(s->precision);
}

void			ft_s_specifier(va_list args, t_list *node)
{
	int			i;
	int			len;
	t_printf	*s;

	s = initializing();
	i = 0;
	if (!node)
		return ;
	i = ft_norme01(s, args, node, i);
	ft_norme02(s, node, i);
	len = ft_atoi(s->precision);
	s->precision = va_arg(args, char *);
	if (!s->precision)
		s->precision = ft_strdup("(null)");
	if (precision_exist(node, i) && len >= 0)
		s->precision = ft_substr(s->precision, 0, len);
	ft_norme03(s);
	node->str = s->string;
}
