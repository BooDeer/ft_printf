/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_speficier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:40:36 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/03 21:50:12 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

void	ft_percent_specifier(va_list args, t_list *node)
{
	int		i;
	char	*string;
	char	flag;
	char	*width;
	int		len;

	len = 0;
	i = 0;
	if (!node)
		return ;
	while(node->flag[i] == '-' || node->flag[i] == '0')
	{
		
		if (flag == '-')
		{
			i++;
			continue;
		}
		flag = node->flag[i++];
	}
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
	if (len != i)
		width = ft_substr(node->flag,len, i - len + 1);
	if (node->flag[i + 2] == '*')
		va_arg(args, int);
	string = (char *)malloc(sizeof(char) * ft_atoi(width) + 1);
	if(flag == '0')
		ft_memset(string, '0', ft_atoi(width));
	else
		ft_memset(string, ' ', ft_atoi(width));
	if (flag == '-')
		string[0] = va_arg(args, int);
	else
		string[ft_atoi(width) - 1] = va_arg(args, int);	
	string[ft_atoi(width)] = '\0';
	node->str = ft_strdup(string);
}