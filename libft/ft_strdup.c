/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:22:28 by hboudhir          #+#    #+#             */
/*   Updated: 2019/10/21 18:23:08 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*tab_dyn;
	int				i;

	i = 0;
	while (s1[i])
		i++;
	tab_dyn = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab_dyn)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tab_dyn[i] = s1[i];
		i++;
	}
	tab_dyn[i] = '\0';
	return (tab_dyn);
}
