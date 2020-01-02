/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:37:36 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/02 20:16:14 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

static char		*ft_hexconv1(size_t c)
{
	char	*hex;
	int		i;
	int		temp;

	i = 0;
	hex = (char *)malloc(sizeof(char) * 20);
	if (!c)
		hex[0] = '0';
	while (c)
	{
		temp = c % 16;
		if (temp < 10)
		{
			hex[i] = temp + 48;
			i++;
		}
		else
		{
			hex[i] = temp + 87;
			i++;
		}
		c /= 16;
	}
	hex = ft_strrev(hex);
	return (hex);
}

static int		ft_norme01(t_printf *p, va_list args, t_list *node, int i)
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

static	void	ft_norme02(t_printf *p, va_list args, t_list *node, int i)
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

void	ft_p_specifier(va_list args, t_list *node)
{
	int		i;
	int		len;
	t_printf *p;

	p = initializing();
	i = 0;
	if (!node)
		return 	;
	i = ft_norme01(p, args, node, i);
	ft_norme02(p, args, node, i);
	len = ft_atoi(p->precision);
	p->precision = ft_strdup(ft_hexconv1(va_arg(args, size_t)));
	if (*p->precision == '0' && len) 
	{	p->precision = ft_strdup("");
		p->precision = ft_strjoin("0x", p->precision);
	}
	else
		p->precision = ft_strjoin("0x", p->precision);	
	if (ft_atoi(p->width) > (int)ft_strlen(p->precision) &&
	ft_atoi(p->width) > len)
	{
		p->string = (char *)malloc(sizeof(char) * ft_atoi(p->width) + 1);
		ft_memset(p->string, ' ', ft_atoi(p->width));
		if (p->flag == '-')
		{
			ft_memset(p->string, '0', len);
			if (len > (int)ft_strlen(p->precision))
				ft_memcpy(&p->string[len - ft_strlen(p->precision)],
				p->precision, ft_strlen(p->precision));
			else
				ft_memcpy(p->string, p->precision,
				ft_strlen(p->precision));
		}
		else if (p->flag == '0')
		{
			ft_memset(p->string, '0', ft_atoi(p->width));
		}
		else
		{
			ft_memset(&p->string[ft_atoi(p->width) - len], '0', len);
			ft_memcpy(&p->string[ft_atoi(p->width) - ft_strlen(p->precision)],
			p->precision, ft_strlen(p->precision));
		}
		
		p->string[ft_atoi(p->width)] = '\0';
	}
	else if (len > (int)ft_strlen(p->precision))
	{
		p->string = (char *)malloc(sizeof(char) * len + 1);
		ft_memset(p->string, '0', len);
		ft_strlcpy(&p->string[len - ft_strlen(p->precision)], p->precision,
		ft_strlen(p->precision) + 1);
		p->string[len] = '\0';
	}
	else
	{
		p->string = (char *)malloc(sizeof(char)* ft_strlen(p->precision) + 1);
		p->string = ft_strdup(p->precision);
		p->string[ft_strlen(p->precision)] = '\0';
	}
	
	node->str = p->string;
}
