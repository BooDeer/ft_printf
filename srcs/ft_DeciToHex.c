/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_DeciToHex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:59:50 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/27 15:31:58 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	i = 0;
	while (i < (len / 2))
	{
		temp = str[i];
		str[i] = str[len - (i + 1)];
		str[len - (i + 1)] = temp;
		i++;
	}
	return (str);
}

char	*ft_hexconv(unsigned int	c)
{
	char 	*hex;
	int		i;
	int		temp;

	i = 0;
	hex = (char *)malloc(sizeof(char) * 20);
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
			hex[i] = temp + 55;
			i++;
		}
		c /= 16;
	}
	hex = ft_strrev(hex);	
	return (hex);
}