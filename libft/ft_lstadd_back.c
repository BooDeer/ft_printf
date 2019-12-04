/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:27:34 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/04 15:29:32 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{    
	t_list		*temp;
    t_list		*p;

	temp = new;
    if (*lst == NULL)
        *lst = temp;
    else
    {
        p = *lst;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;            
    }  
}