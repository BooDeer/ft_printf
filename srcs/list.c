/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:40:22 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/02 22:02:33 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

void	deletinglist(t_list **root)
{
	t_list	*next;
	t_list	*current;

	current = *root;
	while (current)
	{
		next = current->next;
		if (current->cnv)
			free(current->cnv);
		if (current->flag)
			free(current->flag);
		if (current->c == 2)
			--current->str;
		if (current->str)
			free(current->str);
		if (current)
			free(current);
		current = next;
	}
}
