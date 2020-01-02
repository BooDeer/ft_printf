/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:40:40 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/02 17:52:25 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

static int			ft_count(unsigned int n)
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

static char			*print_number(char *number, size_t len, unsigned int nb)
{
	number[--len] = '\0';
	while (nb != '\0' && len > 0)
	{
		number[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (number);
}

static char			*ft_itoa1(unsigned int n)
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

static unsigned int	ft_atoi1(const char *c)
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

static	int			ft_norme01(t_printf *u, va_list args, t_list *node, int i)
{
	int		len;

	while (node->flag[i] == '-' || node->flag[i] == '0')
		u->flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		u->width = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(u->width) < 0)
		{
			u->width++;
			u->flag = '-';
		}
		i++;
	}
	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		u->width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	return (i);
}

static	void		ft_norme02(t_printf *u, va_list args, t_list *node, int i)
{
	int	len;

	if (node->flag[i] == '*')
	{
		u->precision = ft_strdup(ft_itoa(va_arg(args, unsigned int)));
		if (ft_atoi(u->precision) < 0)
			u->precision = ft_strdup("1");
		i++;
	}
	len = i;
	while (ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		u->precision = ft_substr(node->flag, len, i - len + 1);
	if (!u->width)
		u->width = ft_strdup("0");
	if (!u->precision && precision_exist(node, i))
		u->precision = ft_strdup("0");
	else if (!u->precision)
		u->precision = ft_strdup("-1");
}

static	void		ft_norme031(t_printf *u, int len)
{
	if (ft_atoi(u->precision) != -1)
		ft_memset(u->string, '0', ft_atoi1(u->precision));
	if (ft_atoi(u->precision) > ft_count(len))
		ft_memcpy(&u->string[ft_atoi1(u->precision) - ft_count(len) + 1],
		ft_itoa1(len), ft_count(len) - 1);
	else
		ft_memcpy(u->string, ft_itoa1(len), ft_count(len) - 1);
}

static	void		ft_norme03(t_printf *u, int len)
{
	u->string = (char *)malloc(sizeof(char) * ft_atoi1(u->width) + 1);
	if (u->flag == '0')
		ft_memset(u->string, '0', ft_atoi1(u->width));
	else
		ft_memset(u->string, ' ', ft_atoi1(u->width));
	if (ft_atoi1(u->precision) == 0 && len == 0)
		;
	else if (u->flag == '-')
		ft_norme031(u, len);
	else
	{
		if (ft_atoi(u->precision) != -1)
			ft_memset(&u->string[ft_atoi1(u->width) - ft_atoi1(u->precision)],
			'0', ft_atoi1(u->precision));
		if (len == 0 && ft_atoi1(u->precision) == 0)
			;
		else
			ft_memcpy(&u->string[ft_atoi1(u->width) - ft_count(len) + 1]
			, ft_itoa1(len),
		ft_count(len));
	}
}

static	void		ft_norme041(t_printf *u, int len)
{
	u->string = (char *)malloc(sizeof(char) * ft_atoi1(u->precision)
	+ 1);
	ft_memset(u->string, '0', ft_atoi1(u->precision));
	ft_strlcpy(&u->string[ft_atoi1(u->precision) - ft_count(len) + 1],
	ft_itoa1(len),
	ft_count(len));
	u->string[ft_atoi1(u->precision)] = '\0';
}

static	void		ft_norme04(t_printf *u, int len)
{
	if (ft_atoi(u->width) > ft_count(len) - 2 && ft_atoi(u->width) >
	ft_atoi(u->precision))
	{
		ft_norme03(u, len);
		u->string[ft_atoi1(u->width)] = '\0';
	}
	else if (ft_atoi(u->precision) > ft_count(len))
		ft_norme041(u, len);
	else
	{
		if (len == 0 && (ft_atoi1(u->precision) == 0 || ft_atoi1(u->precision)
		== 1) && ft_count(len) == 1)
			u->string = ft_strdup("");
		else
		{
			u->string = (char *)malloc(sizeof(char) * ft_count(len) + 1);
			u->string = ft_strdup(ft_itoa1(len));
			u->string[ft_count(len)] = '\0';
		}
	}
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
	i = ft_norme01(u, args, node, i);
	ft_norme02(u, args, node, i);
	len = va_arg(args, int);
	if (ft_atoi1(u->width) == 0 && ft_atoi1(u->precision)
	== 0 && (len == 0 || ft_count(len) == 0))
		u->string = ft_strdup("");
	else
		ft_norme04(u, len);
	node->str = u->string;
}
