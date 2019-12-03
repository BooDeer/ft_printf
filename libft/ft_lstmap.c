/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:23:17 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/03 18:04:15 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
// {
// 	t_list			*new;
// 	t_list			*current;
// 	current = NULL;
// 	if (!f || !d)
// 		return (NULL);
// 	while (lst != NULL)
// 	{
// 		if (current == NULL)
// 		{
// 			if (!(new = ft_lstnew(f(lst->content))) && !f(lst->content))
// 				return (NULL);
// 			current = new;
// 		}
// 		else
// 		{
// 			if (!(current->next = ft_lstnew(f(lst->content))))
// 				ft_lstclear(&new, d);
// 			current = current->next;
// 		}
// 		lst = lst->next;
// 	}
// 	return (new);
// }