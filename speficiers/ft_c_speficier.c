/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:30:25 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/11 18:07:30 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

void	ft_c_specifier(va_list args, t_list *node)
{
	int		i;
	char	*string;
	char	flag;
	char	*width;
	int		len;

	width = NULL;
	i = 0;
	if (!node)
		return ;
	while(node->flag[i] == '-')
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
	if (len != i)
		width = ft_substr(node->flag,len, i - len + 1);
	if (!width)
		width = ft_strdup("1");
	string = (char *)malloc(sizeof(char) * ft_atoi(width) + 1);
	ft_memset(string, ' ', ft_atoi(width));
	if (flag == '-')
		string[0] = va_arg(args, int);
	else
		string[ft_atoi(width) - 1] = va_arg(args, int);	
	string[ft_atoi(width)] = '\0';
	node->str = ft_strdup(string);
}
