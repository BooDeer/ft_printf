/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:04:21 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/11 23:04:36 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

void		ft_s_specifier(va_list args, t_list *node)
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
	while(ft_isdigit(node->flag[i++]))
		;
	if (len != i)
		width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i++] == '.')
		;
	if (node->flag[i] == '*')
	{
		precision = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(precision) < 0)
			precision = ft_strdup("1");
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i++]))
		;
	if (len != i)
		precision = ft_substr(node->flag, len , i - len + 1);
	if (!width)
		width = ft_strdup("1");
	if (!precision)
		precision = ft_strdup("1");
	string = (char *)malloc(sizeof(char) * ft_atoi(width) + 1);
	ft_memset(string, ' ', ft_atoi(width));
	// if (flag == '-')
	
	
	node->str = va_arg(args, char *);
}
