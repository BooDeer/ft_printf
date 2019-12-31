/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx_speficier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:43:31 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/31 21:58:01 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

static int		ft_norme01(t_printf *a, t_list *node, va_list args)
{
	int		i;

	i = 0;
	a->width = NULL;
	a->precision = NULL;
	while (node->flag[i] == '-' || node->flag[i] == '0')
		a->flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		a->width = ft_itoa(va_arg(args, int));
		if (ft_atoi(a->width) < 0)
		{
			a->width++;
			a->flag = '-';
		}
		i++;
	}
	return (i);
}

static int		ft_norme02(t_printf *a, t_list *node, va_list args, int i)
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
			a->precision = "1";
		i++;
	}
	return (i);
}

static	int		ft_norme03(t_printf *a, t_list *node, va_list args, int i)
{
	int		len;

	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		a->precision = ft_substr(node->flag, len, i - len + 1);
	if (!a->width)
		a->width = "0";
	if (!a->precision && precision_exist(node, i))
		a->precision = "-1";
	else if (!a->precision)
		a->precision = "1";
	len = ft_atoi(a->precision);
	a->precision = ft_hexconv(va_arg(args, unsigned int));
	if (*a->precision == '\0' && len == -1)
		a->precision = "";
	else if (*a->precision == '\0' && len)
		a->precision = "0";
	return (len);
}

static	void	ft_norme04_1(t_printf *a, int len)
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

static	void	ft_norme04(t_printf *a, int len)
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
		ft_norme04_1(a, len);
}

static	void	ft_norme05(t_printf *a, int len)
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
	{
		a->string = (char *)malloc(sizeof(char) * ft_strlen(a->precision) + 1);
		a->string = ft_strdup(a->precision);
		a->string[ft_strlen(a->precision)] = '\0';
	}
}

char			*ft_bigx_specifier(va_list args, t_list *node)
{
	int			len;
	int			i;
	t_printf	*bigx;

	bigx = (t_printf *)malloc(sizeof(t_printf));
	bigx->width = NULL;
	bigx->precision = NULL;
	i = ft_norme01(bigx, node, args);
	i = ft_norme02(bigx, node, args, i);
	len = ft_norme03(bigx, node, args, i);
	if (ft_atoi(bigx->width) > (int)ft_strlen(bigx->precision)
	&& ft_atoi(bigx->width) > len)
		ft_norme04(bigx, len);
	else
		ft_norme05(bigx, len);
	node->str = bigx->string;
	return (bigx->string);
}
