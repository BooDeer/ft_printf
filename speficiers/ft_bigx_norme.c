/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx_norme.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 01:10:46 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/03 02:38:42 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

int		ft_bigx01(t_printf *a, t_list *node, va_list args)
{
	int		i;

	i = 0;
	while (node->flag[i] == '-' || node->flag[i] == '0')
		a->flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		a->width = ft_itoa(va_arg(args, int));
		if (ft_atoi(a->width) < 0)
		{
			a->width = ft_strdup(++a->width);
			a->flag = '-';
		}
		i++;
	}
	return (i);
}

int		ft_bigx02(t_printf *a, t_list *node, va_list args, int i)
{
	int	len;

	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (node->flag[i] == '.' && !a->flag)
		a->flag = '\0';
	if (len != i)
		a->width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	if (node->flag[i] == '*')
	{
		a->precision = ft_itoa(va_arg(args, int));
		if (ft_atoi(a->precision) < 0)
		{
			free(a->precision);
			a->precision = ft_strdup("1");
		}
		i++;
	}
	return (i);
}