/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:13:32 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/04 15:57:39 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "srcs/ft_printf.h"
#include <stdio.h>

// int		get_index(char *str, int start)
// {
// 	char	*cnv;
// 	int		j;

// 	cnv = "cspdiuxX%";
// 	j = 0;
// 	while(str[start])
// 	{
// 		while(cnv[j])
// 		{
// 			if (str[start] == cnv[j])
// 				return (start);
// 			j++;
// 		}
// 		start++;
// 		j = 0;
// 	}
// 	return (0);
// }

// void	get_ls(char	*str, t_list **root)
// {
// 	size_t	i;
// 	size_t	start;
// 	size_t	skipcnv;                                                              

// 	start = 0;
// 	i = -1;
// 	while(str[++i])
// 	{
// 		if ((str[i + 1] == '%' || str[i + 1] == '\0') && str[i] != '%')
// 			ft_lstadd_back(root, ft_lstnew(ft_substr(str, start, (i - start) + 1), '\0', NULL));

// 		if (str[i] == '%')
// 		{
// 			start = i;
// 			skipcnv = get_index(str, start + 1);
// 			ft_lstadd_back(root, ft_lstnew(NULL, *ft_substr(str, skipcnv, 1), ft_substr(str, i + 1,skipcnv - i - 1)));
// 			start = skipcnv + 1;
// 			i = skipcnv + 1;
// 		}
// 	}
// 	return ;
// }

void	ft_put_arg(va_list args, t_list *node,char c)
{
	if (c == 'c')
		ft_c_specifier(args, node);
	// else if (c == 's')
	// 	ft_s_specifier(args, node);
	// else if (c == 'p')
	// 	ft_p_specifier(args, node);
	// else if (c == 'x')
	// 	ft_x_specifier(args, node);
	// else if (c == 'X')
	// 	ft_bigx_specifier(args, node);
	// else if (c == 'd')
	// 	ft_d_specifier(args, node);
	// else if (c == 'i')
	// 	ft_i_specifier(args, node);
	// else if (c == '%')
	// 	ft_percent_specifier(args, node);
	// else if (c == 'u')
	// 	ft_u_speficier(args, node);
	return ;			
}
void	get_args(t_list **root, va_list args)
{
	t_list		*temp;

	temp = *root;
	while(temp)
	{
		// printf("ZZ\n");
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
	// ft_printf("%%without %sany %dvariadic %dargument!\n%s\n%s", "this is a test", "hehehehehhehe");
	// printf("%%\n");
	ft_printf("%chis i%-2c %*c\n", 't', 's', 10, 'z');
	printf("%chis i%-2c %*c", 't', 's',10, 'z');
	return (0);
}