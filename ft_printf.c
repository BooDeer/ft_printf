/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:13:32 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/01 16:38:42 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "srcs/ft_printf.h"
#include <stdio.h>

int		get_index(char *str, int start)
{
	int		k;
	char	*cnv;
	int		j;

	cnv = "cspdiuxX%";
	k = 1;
	j = 0;
	while(str[i] && k)
	{
		while(cnv[j])
		{
			if (str[i] == cnv[j])
			{
				return (i)
			}
		}
		j = 0;
	}
}

void	get_ls(char	*str, va_list args, t_list **root)
{
	size_t	i;
	size_t	start;
	size_t	skipcnv;                                                              
	char	*cpy;
	char	*flg;

	start = 0;
	i = -1;
	while(str[++i])
	{
		if ((str[i + 1] == '%' || str[i + 1] == '\0') && str[i] != '%')
			ft_lstadd_back(root, ft_lstnew(ft_substr(str, start, (i - start) + 1), '\0', NULL));
		if (str[i] == '%' && str[i + 1] == '%')
		{
			start = i;
			ft_lstadd_back(root, ft_lstnew(ft_substr(str, start, (i - start) + 1), '\0', NULL));
			start = i + 2;
		}
		if (str[i] == '%' && str[i + 1] != '\0' && str[i + 1] != '%')
		{
			if ((skipcnv = get_index(str, start)))
			{
				
			}
		}
	}
}

void		ft_printf(const char *str, ...)
{
	va_list		args;
	t_list		*root;
	
	root = NULL;
	va_start(args, str);
	get_ls((char *)str, args, &root);
	
	
	return ;
}

int	main()
{
	ft_printf("this is a long test %%without any variadic argument!\n%s\n%s%qkdqlkds", "this is a test", "hehehehehhehe");
	return (0);
}