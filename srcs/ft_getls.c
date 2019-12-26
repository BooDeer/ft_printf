/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:58:47 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/26 14:54:24 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/ft_printf.h"

/*
* This function allows us to know the length of
* the string starting from the '%' until the
* first speficier encountered
*/
static	int		get_index(char *str, int start)
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
static	int		check_index(char str, int i)
{
	char	*cnv;
	int		j;

	cnv = "cspdiuxX%";
	j = 0;
	while(cnv[j])
	{
		if (str == cnv[j] && i != 0)
			return (0);
		j++;
	}
	return (1);
}
/*
* This function allows us to get each string or combinaison of
* flags, width and precision in seperated nodes
*
*/
void	get_ls(char	*str, t_list **root)
{
	size_t	i;
	size_t	start;
	size_t	skipcnv;                                                              

	start = 0;
	i = -1;
	while(str[++i])
	{
		if (str[i] == '%')
		{
			start = i + 1;
			skipcnv = get_index(str, start);
			ft_lstadd_back(root, ft_lstnew(NULL, *ft_substr(str, skipcnv, 1), ft_substr(str, i + 1,skipcnv - i - 1)));
			start = skipcnv;
			i = skipcnv;
		}
		else if ((str[i + 1] == '%' || str[i + 1] == '\0') && str[i] != '%')
		{
			if (check_index(str[start], start))
				ft_lstadd_back(root, ft_lstnew(ft_substr(str, start, (i - start) + 1), '\0', NULL));
			else
				ft_lstadd_back(root, ft_lstnew(ft_substr(str, start +1, (i - start)), '\0', NULL));
		}
	}
	
	return ;
}
