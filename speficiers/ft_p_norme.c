/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_norme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 03:04:33 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/03 03:05:57 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

int		ft_p_speficier01(t_printf *p, va_list args, t_list *node, int i)
{
	int		len;

	while (node->flag[i] == '-' || node->flag[i] == '0')
		p->flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		p->width = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(p->width) < 0)
		{
			p->width++;
			p->flag = '-';
		}
		i++;
	}
	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (node->flag[i] == '.' && !p->flag)
		p->flag = '\0';
	if (len != i)
		p->width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	return (i);
}

void	ft_p_speficier02(t_printf *p, va_list args, t_list *node, int i)
{
	int	len;

	if (node->flag[i] == '*')
	{
		p->precision = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(p->precision) < 0)
			p->precision = ft_strdup("1");
		i++;
	}
	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		p->precision = ft_substr(node->flag, len, i - len + 1);
	if (!p->width)
		p->width = ft_strdup("1");
	(p->precision || node->flag[i - 1] == '.') ? (p->precision =
	ft_strdup("1")) : (p->precision = ft_strdup("0"));
}
