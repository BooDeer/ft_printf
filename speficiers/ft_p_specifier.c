/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:37:36 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/23 15:35:57 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

static char	*ft_hexconv1(size_t	c)
{
	char 	*hex;
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

void	ft_p_specifier(va_list args, t_list *node)
{
	int		i;
	char	*string = NULL;
	char	flag;
	char	*width;
	int		len;
	char	*precision;

	width = NULL;
	precision = NULL;
	i = 0;
	if (!node)
		return 	;
	while (node->flag[i] == '-' || node->flag[i] == '0')
		flag = node->flag[i++];
	if (node->flag[i] == '*')
	{
		width = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(width) < 0)
		{
			width++;
			flag = '-';
		}
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (node->flag[i] == '.' && !flag)
		flag = '\0';
	if (len != i)
		width = ft_substr(node->flag, len, i - len + 1);
	if (node->flag[i] == '.')
		i++;
	if (node->flag[i] == '*')
	{
		precision = ft_strdup(ft_itoa(va_arg(args, int)));
		if (ft_atoi(precision) < 0)
			precision = ft_strdup("1");
		i++;
	}
	len = i;
	while(ft_isdigit(node->flag[i]))
		i++;
	if (len != i)
		precision = ft_substr(node->flag, len , i - len + 1);
	if (!width)
		width = ft_strdup("1");
	if (!precision)
		precision = ft_strdup("1");
	len = ft_atoi(precision);
	precision = ft_strdup(ft_hexconv1(va_arg(args, size_t)));
	precision = ft_strjoin("0x", precision);
	if (ft_atoi(width) > (int)ft_strlen(precision) && ft_atoi(width) > len)
	{
		string = (char *)malloc(sizeof(char) * ft_atoi(width) + 1);
		ft_memset(string, ' ', ft_atoi(width));
		if (flag == '-')
		{
			ft_memset(string, '0', len);
			if (len > (int)ft_strlen(precision))
				ft_memcpy(&string[len - ft_strlen(precision)], precision, ft_strlen(precision));
			else
				ft_memcpy(string, precision, ft_strlen(precision));
		}
		else if (flag == '0')
		{
			ft_memset(string, '0', ft_atoi(width));
		}
		else
		{
			ft_memset(&string[ft_atoi(width) - len], '0', len);
			ft_memcpy(&string[ft_atoi(width) - ft_strlen(precision)], precision, ft_strlen(precision));
		}
		
		string[ft_atoi(width)] = '\0';
	}
	else if (len > (int)ft_strlen(precision))
	{
		string = (char *)malloc(sizeof(char) * len + 1);
		ft_memset(string, '0', len);
		ft_strlcpy(&string[len - ft_strlen(precision)], precision, ft_strlen(precision) + 1);
		string[len] = '\0';
	}
	else
	{
		string = (char *)malloc(sizeof(char)* ft_strlen(precision) + 1);
		string = ft_strdup(precision);
		string[ft_strlen(precision)] = '\0';
	}
	
	node->str = string;
}
