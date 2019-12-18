/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:50:21 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/16 21:54:27 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int count;

	count = 1;
	if (n < 0)
		count++;
	if (n == 0)
		count = 2;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char		*print_number(char *number, size_t len, unsigned int nb)
{
	number[--len] = '\0';
	while (nb != '\0' && len > 0)
	{
		number[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (number);
}

char			*ft_itoa(int n)
{
	int				nb;
	size_t			len;
	char			*number;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
	if (n < 0)
	{
		nb = -n;
		*number = '-';
	}
	return (print_number(number, len, nb));
}
