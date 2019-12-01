/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:47:12 by hboudhir          #+#    #+#             */
/*   Updated: 2019/11/29 16:10:59 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*temp;
	t_list		*fr;

	temp = ft_lstnew(NULL);
	temp = *lst;
	if (!lst)
		return ;
	while (temp->next)
	{
		fr = temp->next;
		if(temp->next && del)
			del(temp->next);
		free(temp);
		temp = fr;	
	}
	*lst = NULL;
}