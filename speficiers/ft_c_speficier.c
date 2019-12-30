/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:30:25 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/30 16:58:01 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"
#include <stdio.h>

void	ft_c_specifier(va_list args, t_list *node)
{
	int		i;
	int		len;

	t_printf a;
	a.width = NULL;
	i = 0;
	if (!node)
		return ;
	node->c = 0;
	while(node->flag[i] == '-')
		a.flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		a.width = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(a.width) < 0)
		{
			a.width++;
			a.flag = '-';
		}
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		a.width = ft_substr(node->flag,len, i - len + 1);
	if (!a.width || ft_atoi(a.width) == 0)
		a.width = ft_strdup("1");
	a.string = (char *)malloc(sizeof(char) * ft_atoi(a.width) + 1);
	a.string[ft_atoi(a.width)] = '\0';
	ft_memset(a.string, ' ', ft_atoi(a.width));
	if (a.flag == '-')
	{
		a.string[0] = va_arg(args, int);
		if (!a.string[0])
		{
			a.string = &a.string[1];
			node->c = 2;
		}
	}
	else
	{
		a.string[ft_atoi(a.width) - 1] = va_arg(args, int);	
		if (a.string[ft_atoi(a.width) - 1] == '\0' && node->flag)
			node->c = 1;
	}
	node->str = a.string;
}
