/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_speficier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:40:43 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/02 17:40:45 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

void	ft_x_specifier(va_list args, t_list *node)
{
	char	*string;
	size_t	i;

	i = 0;
	if (!node)
		return ;
	string = ft_bigx_specifier(args, node);
	while (string[i])
	{
		if (ft_isalpha(string[i]))
			string[i] = ft_tolower(string[i]);
	}
	node->str = string;
}
