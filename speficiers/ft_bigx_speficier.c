  
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx_speficier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:43:31 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/26 12:20:30 by hboudhir         ###   ########.fr       */
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

char			*ft_bigx_specifier(va_list args, t_list *node)
{
	int		len;
	int		i;
	t_printf *bigx;

	bigx = (t_printf *)malloc(sizeof(t_printf));
	bigx->width = NULL;
	bigx->precision = NULL;
	
	i = ft_norme01(bigx, node, args);

	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (node->flag[i] == '.' && !bigx->flag)
		bigx->flag = '\0';
	if (len != i)
		bigx->width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	if (node->flag[i] == '*')
	{
		bigx->precision = ft_itoa(va_arg(args, int));
		if (ft_atoi(bigx->precision) < 0)
			bigx->precision = "1";
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		bigx->precision = ft_substr(node->flag, len , i - len + 1);
	if (!bigx->width)
		bigx->width = "0";
	if (!bigx->precision && precision_exist(node, i))
		bigx->precision = "-1";
	else if (!bigx->precision)
		bigx->precision = "1";
	len = ft_atoi(bigx->precision);
	bigx->precision = ft_hexconv(va_arg(args, unsigned int));
	if (*bigx->precision == '\0' && len == -1)
		bigx->precision = "";
	else if (*bigx->precision == '\0' && len)
		bigx->precision = "0";	
	if (ft_atoi(bigx->width) > (int)ft_strlen(bigx->precision) && ft_atoi(bigx->width) > len)
	{
		bigx->string = (char *)malloc(sizeof(char) * ft_atoi(bigx->width) + 1);
		ft_memset(bigx->string, ' ', ft_atoi(bigx->width));
		if (bigx->flag == '-')
		{
			if (len != -1)
				ft_memset(bigx->string, '0', len);
			if (len > (int)ft_strlen(bigx->precision))
				ft_memcpy(&bigx->string[len - ft_strlen(bigx->precision)], bigx->precision, ft_strlen(bigx->precision));
			else
				ft_memcpy(bigx->string, bigx->precision, ft_strlen(bigx->precision));
		}
		else if (bigx->flag == '0')
		{
			ft_memset(bigx->string, '0', ft_atoi(bigx->width));
			ft_memcpy(&bigx->string[ft_atoi(bigx->width) - ft_strlen(bigx->precision)], bigx->precision, ft_strlen(bigx->precision));
		}
		else
		{	
			if (len != -1)
				ft_memset(&bigx->string[ft_atoi(bigx->width) - len], '0', len);
			ft_memcpy(&bigx->string[ft_atoi(bigx->width) - ft_strlen(bigx->precision)], bigx->precision, ft_strlen(bigx->precision));
		}
		
		bigx->string[ft_atoi(bigx->width)] = '\0';
	}
	else if (len > (int)ft_strlen(bigx->precision))
	{
		bigx->string = (char *)malloc(sizeof(char) * len + 1);
		ft_memset(bigx->string, '0', len);
		ft_strlcpy(&bigx->string[len - ft_strlen(bigx->precision)], bigx->precision, ft_strlen(bigx->precision) + 1);
		bigx->string[len] = '\0';
	}
	else
	{
		bigx->string = (char *)malloc(sizeof(char)* ft_strlen(bigx->precision) + 1);
		bigx->string = ft_strdup(bigx->precision);
		bigx->string[ft_strlen(bigx->precision)] = '\0';
	}

	node->str = bigx->string;
	return (bigx->string);
}