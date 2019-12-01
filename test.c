/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:49:59 by hboudhir          #+#    #+#             */
/*   Updated: 2019/11/30 22:50:27 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef    struct    z_list
{
    char            *str;
    struct z_list        *next;
}                t_list;

t_list    *ft_lstnew(char *str)
{
    t_list    *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->str = str;
    new->next = NULL;
    return (new);
}

void    ft_lstadd_back(t_list **lst,char *str)
{    
    t_list *temp;
    t_list *p;
    
    p = *lst;
    temp = ft_lstnew(str);
    if (*lst == NULL)
        *lst = temp;
    else
    {
        while (p->next != NULL)
            p = p->next;
        p->next = temp;            
    }  
}

int main()
{
  t_list *root =NULL;
  ft_lstadd_back(&root,"this is a test1");
  ft_lstadd_back(&root,"this is a test2");

}