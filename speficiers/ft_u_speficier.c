/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:40:40 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/03 03:49:18 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

int					ft_count(unsigned int n)
{
	int count;

	count = 1;
	if (n == 0)
		count = 2;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char				*ft_itoa1(unsigned int n)
{
	unsigned int				nb;
	size_t						len;
	char						*number;

	nb = n;
	len = ft_count(n);
	number = (char *)malloc(len);
	if (!number)
		return (NULL);
	if (n == 0)
	{
		*number = '0';
		*(number + 1) = '\0';
		return (number);
	}
	return (print_number(number, len, nb));
}

unsigned int		ft_atoi1(const char *c)
{
	int		i;
	int		signe;
	long	res;

	i = 0;
	signe = 1;
	res = 0;
	while (c[i] && (c[i] == '\t' || c[i] == '\n' || c[i] == '\r' || c[i] == '\v'
				|| c[i] == '\f' || c[i] == ' '))
		i++;
	if (c[i] == '-')
		signe = -1;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (ft_isdigit(c[i]))
	{
		res = (res * 10) + (c[i] - '0');
		if ((res * signe) > 2147483647)
			return (-1);
		else if ((res * signe) < -2147483648)
			return (0);
		i++;
	}
	return ((int)(res * signe));
}

void				ft_u_specifier(va_list args, t_list *node)
{
	unsigned int		i;
	unsigned int		len;
	t_printf			*u;

	u = initializing();
	i = 0;
	if (!node)
		return ;
	i = ft_u_speficier01(u, args, node, i);
	ft_u_speficier02(u, args, node, i);
	len = va_arg(args, int);
	if (ft_atoi(u->precision) < ft_count(len) - 1)
		if (u->flag == '0' && ft_atoi(u->precision) >= 0)
			u->flag = '\0';
	if (ft_atoi(u->precision) >= ft_count(len) - 1)
		if (u->flag == '0')
			u->flag = '\0';
	if (ft_atoi1(u->width) == 0 && ft_atoi1(u->precision)
	== 0 && (len == 0 || ft_count(len) == 0))
		u->string = ft_strdup("");
	else
		ft_u_speficier04(u, len);
	node->str = u->string;
}
