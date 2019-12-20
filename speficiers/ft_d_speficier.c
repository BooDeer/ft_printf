/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:56 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/18 15:34:03 by hboudhir         ###   ########.fr       */
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

void	ft_d_specifier(va_list args, t_list *node)
{
	int		i;
	char	*string;
	char	flag;
	char	*width;
	int		len;
	char	*precision;

	width = NULL;
	precision = NULL;
	i = 0;
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
			precision = ft_strdup("1");
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		precision = ft_substr(node->flag, len , i - len + 1);
	if (!width)
		width = ft_strdup("1");
	if (!precision)
		precision = ft_strdup("1");
	len = va_arg(args, int);
	if (ft_atoi(width) == 0 && ft_atoi(precision) == 0 && (len == 0 || ft_count(len) == 0))
		string = ft_strdup("");
	else if (ft_atoi(width) > ft_count(len) - 1&& ft_atoi(width) > ft_atoi(precision))
	{
		string = (char *)malloc(sizeof(char) * ft_atoi(width) + 1);
		ft_memset(string, ' ', ft_atoi(width));
		if (ft_atoi(precision) == 0 && len == 0)
			;
		else if (flag == '-')
		{
			ft_memset(string, '0', ft_atoi(precision));
			if (ft_atoi(precision) > ft_count(len))
				ft_memcpy(&string[ft_atoi(precision) - ft_count(len) + 1], ft_itoa(len), ft_count(len) - 1);
			else
				ft_memcpy(string, ft_itoa(len), ft_count(len) - 1);			
		}
		else
		{
			ft_memset(&string[ft_atoi(width) - ft_atoi(precision)], '0', ft_atoi(precision));
			if (len < 0)
			{
				len *= -1;
				if (ft_count(len) > ft_atoi(precision))
					string[ft_atoi(width) - ft_count(len)] = '-';
				else
					string[ft_atoi(width) - ft_atoi(precision) - 1] = '-';
			}
			if (len == 0 && ft_atoi(precision) == 0)
				;
			else
				ft_memcpy(&string[ft_atoi(width) - ft_count(len) + 1], ft_itoa(len),
			ft_count(len));
		}
		string[ft_atoi(width)] = '\0';
	}
	else if (ft_atoi(precision) > ft_count(len))
	{
		if (len < 0)
		{	precision = ft_strdup(ft_itoa(ft_atoi(precision) + 1));
			string = (char *)malloc(sizeof(char) * ft_atoi(precision) + 1);
		}
		else
			string = (char *)malloc(sizeof(char) * ft_atoi(precision) + 1);
		ft_memset(string, '0', ft_atoi(precision));
		if (len < 0)
		{
			len *= -1;
			string[0] = '-';
		}
		ft_strlcpy(&string[ft_atoi(precision) - ft_count(len) + 1], ft_itoa(len), 
		ft_count(len));
		string[ft_atoi(precision)] = '\0';
	}
	else
	{
		if (len == 0 && (ft_atoi(precision) == 0 || ft_atoi(precision) == 1) && ft_count(len) == 1)
			string = ft_strdup("");		
		else
		{
			string = (char *)malloc(sizeof(char) * ft_count(len) + 1);
			string = ft_strdup(ft_itoa(len));
			string[ft_count(len)] = '\0';
		}
	}
	node->str = string;
}
