/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:13:32 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/18 18:59:02 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "srcs/ft_printf.h"
#include <stdio.h>

void	ft_put_arg(va_list args, t_list *node,char c)
{
	if (c == 'c')
		ft_c_specifier(args, node);
	else if (c == 's')
		ft_s_specifier(args, node);
	// else if (c == 'p')
	// 	ft_p_specifier(args, node);
	else if (c == 'x')
		ft_x_specifier(args, node);
	else if (c == 'X')
		ft_bigx_specifier(args, node);
	else if (c == 'd' || c == 'i')
		ft_d_specifier(args, node);
	else if (c == '%')
		ft_percent_specifier(args, node);
	else if (c == 'u')
		ft_u_specifier(args, node);
	return ;			
}

void	get_args(t_list **root, va_list args)
{
	t_list		*temp;

	temp = *root;
	while(temp)
	{
		 if (temp->cnv != '\0')
		 	ft_put_arg(args, temp, temp->cnv);
		temp = temp->next;
	}
}
void		ft_print_node(t_list **root)
{
	t_list	*temp;

	temp = *root;
	while(temp)
	{
		ft_putstr(temp->str);
		temp = temp->next;
	}
}
void		ft_printf(const char *str, ...)
{
	va_list		args;
	t_list		*root;

	root = NULL;
	va_start(args, str);
	get_ls((char *)str, &root);
	get_args(&root, args);
	ft_print_node(&root);
	
	return ;
}

int	main()
{
	int c = 3;
	// ft_printf("%%without %sany %dvariadic %dargument!\n%s\n%s", "this is a test", "hehehehehhehe");
	// ft_printf("|%u|\n", -2147483647);
	   printf("|%p|\n", &c);
	return (0);
}