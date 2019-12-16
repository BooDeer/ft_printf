/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:04:21 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/16 20:54:34 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int			precision_exist(t_list *node, int i)
{
	while(node->flag[i] != '%')
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
	char	*string = NULL;
	char	flag;
	char	*width;
	int		len;
	char	*precision;

	i = 0;
	precision = NULL;
	width = NULL;
	if (!node)
		return ;
	while (node->flag[i] == '-' || node->flag[i] == '0')
		flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		width = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(width) < 0)
		{
			width++;
			flag = '-';
		}
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	if (node->flag[i] == '*')
	{
		precision = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(precision) < 0)
			precision = ft_strdup("-2");
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		precision = ft_substr(node->flag, len , i - len + 1);
	if (!width)
		width = ft_strdup("1");
	if (!precision && node->flag[i] == '.')
		precision = ft_strdup("0");
	else if (!precision)
		precision = ft_strdup("0");
	len = ft_atoi(precision);
	precision = va_arg(args, char *);
	if (precision_exist(node, i) && len >= 0)
			precision = ft_substr(precision, 0, len);
	if (ft_atoi(width) > (int)ft_strlen(precision))
	{
		string = (char *)malloc(sizeof(char) * ft_atoi(width) + 1);
		ft_memset(string, ' ', ft_atoi(width));
		if (ft_strlen(precision))
		{
			if (flag == '-')
				ft_memmove(string, precision, ft_strlen(precision));
			else
				ft_strlcpy(&string[ft_atoi(width) - ft_strlen(precision)] , precision, ft_strlen(precision) + 1);
			string[ft_atoi(width)] = '\0';
		}
		else if (ft_atoi(width) == 1)
			string[ft_atoi(width) - 1] = '\0';		
		
	}
	else
		string = ft_strdup(precision);
	
	
	
	node->str = string;
}
