/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx_speficier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:43:31 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/03 02:41:58 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

static	int		bigx03(t_printf *a, t_list *node, va_list args, int i)
{
	int		len;

	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		a->precision = ft_substr(node->flag, len, i - len + 1);
	if (!a->width)
		a->width = ft_strdup("0");
	if (!a->precision && precision_exist(node, i))
		a->precision = ft_strdup("-1");
	else if (!a->precision)
		a->precision = ft_strdup("1");
	len = ft_atoi(a->precision);
	ft_hexconv(va_arg(args, unsigned int), a);
	if (*a->precision == '\0' && len == -1)
		a->precision = "";
	else if (*a->precision == '\0' && len)
		a->precision = "0";
	return (len);
}

static	void	bigx04_1(t_printf *a, int len)
{
	if (a->flag == '0')
	{
		ft_memset(a->string, '0', ft_atoi(a->width));
		ft_memcpy(&a->string[ft_atoi(a->width) - ft_strlen(a->precision)],
			a->precision, ft_strlen(a->precision));
	}
	else
	{
		if (len != -1)
			ft_memset(&a->string[ft_atoi(a->width) - len], '0', len);
		ft_memcpy(&a->string[ft_atoi(a->width) - ft_strlen(a->precision)],
		a->precision, ft_strlen(a->precision));
	}
	a->string[ft_atoi(a->width)] = '\0';
}

static	void	bigx04(t_printf *a, int len)
{
	a->string = (char *)malloc(sizeof(char) * ft_atoi(a->width) + 1);
	ft_memset(a->string, ' ', ft_atoi(a->width));
	if (a->flag == '-')
	{
		if (len != -1)
			ft_memset(a->string, '0', len);
		if (len > (int)ft_strlen(a->precision))
			ft_memcpy(&a->string[len - ft_strlen(a->precision)],
				a->precision, ft_strlen(a->precision));
		else
			ft_memcpy(a->string, a->precision, ft_strlen(a->precision));
	}
	else
		bigx04_1(a, len);
}

static	void	bigx05(t_printf *a, int len)
{
	if (len > (int)ft_strlen(a->precision))
	{
		a->string = (char *)malloc(sizeof(char) * len + 1);
		ft_memset(a->string, '0', len);
		ft_strlcpy(&a->string[len - ft_strlen(a->precision)],
		a->precision, ft_strlen(a->precision) + 1);
		a->string[len] = '\0';
	}
	else
		a->string = ft_strdup(a->precision);
}

char			*ft_bigx_specifier(va_list args, t_list *node)
{
	int			len;
	int			i;
	t_printf	*bigx;

	bigx = initializing();
	i = ft_bigx01(bigx, node, args);
	i = ft_bigx02(bigx, node, args, i);
	len = bigx03(bigx, node, args, i);
	if (len < (int)ft_strlen(bigx->precision))
    	if (len >= -1 && bigx->flag == '0')
            bigx->flag = '\0';
	if (len >= (int)ft_strlen(bigx->precision))
	    if (bigx->flag == '0')
           	bigx->flag = '\0';
	if (ft_atoi(bigx->width) > (int)ft_strlen(bigx->precision)
	&& ft_atoi(bigx->width) > len)
		bigx04(bigx, len);
	else
		bigx05(bigx, len);
	node->str = ft_strdup(bigx->string);
	return (node->str);
}