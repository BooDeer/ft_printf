/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_speficier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:40:36 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/02 14:51:12 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

static int		norme01(t_printf *pr, va_list args, t_list *node, int i)
{
	while (node->flag[i] == '-' || node->flag[i] == '0')
	{
		if (pr->flag == '-')
		{
			pr->flag = '-';
			i++;
			continue;
		}
		else
			pr->flag = '0';
		pr->flag = node->flag[i++];
	}
	if (node->flag[i] == '*')
	{
		pr->width = ft_itoa(va_arg(args, int));
		if (ft_atoi(pr->width) < 0)
		{
			pr->width = ft_strdup(++pr->width);
			pr->flag = '-';
		}
		i++;
	}
	return (i);
}

static	void	norme03(t_printf *pr)
{
	pr->string = (char *)malloc(sizeof(char) * ft_atoi(pr->width) + 1);
	if (pr->flag == '0')
		ft_memset(pr->string, '0', ft_atoi(pr->width));
	else
		ft_memset(pr->string, ' ', ft_atoi(pr->width));
	if (pr->flag == '-')
		pr->string[0] = '%';
	else
		pr->string[ft_atoi(pr->width) - 1] = '%';
}

void			ft_percent_specifier(va_list args, t_list *node)
{
	int			i;
	int			len;
	t_printf	*pr;

	pr = initializing();
	len = 0;
	i = 0;
	if (!node)
		return ;
	i = norme01(pr, args, node, i);
	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		pr->width = ft_substr(node->flag, len, i - len + 1);
	if (!pr->width || ft_atoi(pr->width) == 0)
		pr->width = ft_strdup("1");
	if (node->flag[i + 1] == '*')
		va_arg(args, int);
	norme03(pr);
	pr->string[ft_atoi(pr->width)] = '\0';
	node->str = ft_strdup(pr->string);
}
