/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:58:47 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/03 02:46:44 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

/*
** 	This function allows us to know the length of
**	the string starting from the '%' until the
** 	first speficier encountered
*/

static int			get_index(char *str, int start)
{
	char	*cnv;
	int		j;

	cnv = "cspdiuxX%";
	j = 0;
	while (str[start])
	{
		while (cnv[j])
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

static int			check_index(char str, int i)
{
	char	*cnv;
	int		j;

	cnv = "cspdiuxX%";
	j = 0;
	while (cnv[j])
	{
		if (str == cnv[j] && i != 0)
			return (0);
		j++;
	}
	return (1);
}

/*
** This function allows us to get each string or combinaison of
** flags, width and precision in seperated nodes
*/

void				get_ls(char *s, t_list **root)
{
	t_index z;

	z.start = 0;
	z.i = -1;
	while (s[++z.i])
	{
		if (s[z.i] == '%')
		{
			z.start = z.i + 1;
			z.skipcnv = get_index(s, z.start);
			ft_lstadd_back(root, ft_lstnew(NULL, ft_substr(s, z.skipcnv, 1),
			(ft_substr(s, z.i + 1, z.skipcnv - z.i - 1))));
			z.start = z.skipcnv;
			z.i = z.skipcnv;
		}
		else if ((s[z.i + 1] == '%' || s[z.i + 1] == '\0') && s[z.i] != '%')
		{
			if (check_index(s[z.start], z.start))
				ft_lstadd_back(root, ft_lstnew(ft_substr(s, z.start,
				(z.i - z.start) + 1), ft_strdup("\0"), NULL));
			else
				ft_lstadd_back(root, ft_lstnew(ft_substr(s, z.start + 1,
				(z.i - z.start)), ft_strdup("\0"), NULL));
		}
	}
}

void				free_struct(t_printf *a)
{
	if (a->precision)
		free(a->precision);
	if (a->width)
		free(a->width);
	if (a->string)
		free(a->string);
}

t_printf			*initializing(void)
{
	t_printf		*a;

	a = (t_printf *)malloc(sizeof(t_printf));
	a->flag = '\0';
	a->precision = NULL;
	a->string = NULL;
	a->width = NULL;
	a->d = 0;
	return (a);
}
