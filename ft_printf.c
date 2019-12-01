/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:13:32 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/01 18:55:49 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "srcs/ft_printf.h"
#include <stdio.h>

int		get_index(char *str, int start)
{
	char	*cnv;
	int		j;

	cnv = "cspdiuxX%";
	j = 0;
	while(str[start])
	{
		while(cnv[j])
		{
			if (str[start] == cnv[j])
				return (start);
			j++;
		}
		start++;
		j = 0;
	}
	return (0);
}

void	get_ls(char	*str, t_list **root)
{
	size_t	i;
	size_t	start;
	size_t	skipcnv;                                                              

	start = 0;
	i = -1;
	while(str[++i])
	{
		if ((str[i + 1] == '%' || str[i + 1] == '\0') && str[i] != '%')
			ft_lstadd_back(root, ft_lstnew(ft_substr(str, start, (i - start) + 1), '\0', NULL));

		if (str[i] == '%')
		{
			start = i;
			skipcnv = get_index(str, start + 1);
			ft_lstadd_back(root, ft_lstnew(NULL, *ft_substr(str, skipcnv, 1), ft_substr(str, i + 1,skipcnv - i - 1)));
			start = skipcnv + 1;
			i = skipcnv + 1;
		}
	}
	return ;
}
void		ft_printf(const char *str, ...)
{
	va_list		args;
	t_list		*root;
	
	root = NULL;
	va_start(args, str);
	get_ls((char *)str, &root);
	
	
	return ;
}

int	main()
{
	ft_printf("%%without any variadic argument!\n%s\n%s", "this is a test", "hehehehehhehe");
	return (0);
}