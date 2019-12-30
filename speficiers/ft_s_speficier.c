/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:04:21 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/30 18:08:50 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int			precision_exist(t_list *node, int i)
{
	i--;
	while(node->flag[i] != '%' && node->flag[i])
	{
		if (node->flag[i] == '.')
			return (1);
		i--;
	}
	return (0);
}

void		ft_s_specifier(va_list args, t_list *node)
{
	int		i;
	int		len;

	t_printf s;
	i = 0;
	s.flag = '\0';
	s.precision = NULL;
	s.width = NULL;
	if (!node)
		return ;
	while (node->flag[i] == '-' || node->flag[i] == '0')
		s.flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		s.width = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(s.width) < 0)
		{
			s.width++;
			s.flag = '-';
		}
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		s.width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	if (node->flag[i] == '*')
	{
		s.precision = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(s.precision) < 0)
			s.precision = ft_strdup("-2");
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		s.precision = ft_substr(node->flag, len , i - len + 1);
	if (!s.width)
		s.width = ft_strdup("0");
	if (!s.precision && node->flag[i] == '.')
		s.precision = ft_strdup("0");
	else if (!s.precision)
		s.precision = ft_strdup("0");
	len = ft_atoi(s.precision);
	s.precision = va_arg(args, char *);
	if (!s.precision)
		s.precision = ft_strdup("(null)");
	if (precision_exist(node, i) && len >= 0)
			s.precision = ft_substr(s.precision, 0, len);
	if (ft_atoi(s.width) > (int)ft_strlen(s.precision))
	{
		s.string = (char *)malloc(sizeof(char) * ft_atoi(s.width) + 1);
		ft_memset(s.string, ' ', ft_atoi(s.width));
		if (ft_strlen(s.precision))
		{
			if (s.flag == '-')
				ft_memmove(s.string, s.precision, ft_strlen(s.precision));
			else
				ft_strlcpy(&s.string[ft_atoi(s.width) - ft_strlen(s.precision)] , s.precision, ft_strlen(s.precision) + 1);
			s.string[ft_atoi(s.width)] = '\0';
		}
		else if (ft_atoi(s.width) == 1)
			s.string[ft_atoi(s.width)] = '\0';
	}
	else
		s.string = ft_strdup(s.precision);
	node->str = s.string;
}
