/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:56 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/11 23:22:58 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

void	ft_d_specifier(va_list args, t_list *node)
{
	int		i;
	char	*string;
	char	flag;
	char	*width;
	int		len;
	char	*precision;

	width = NULL;
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
	if (ft_atoi(width) > ft_atoi(precision))
	{
		string = (char *)malloc(sizeof(char) * ft_atoi(width) + 1);
		len = ft_atoi(width);
	}
	else
	{
		string = (char *)malloc(sizeof(char) * ft_atoi(precision) + 1);
		len = ft_atoi(precision);
	}
	ft_memset(string, '0', ft_atoi(precision));
	
	
	string[len] = '\0';
	node->str = va_arg(args, char *);
}
