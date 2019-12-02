/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:37:43 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/02 22:00:51 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void		ft_putstr(char *c);
void		ft_putchar(char c);
char		*ft_test(char c);
int			skip_spefix(char c, char *set);
void		get_ls(char	*str, t_list **root);
void		ft_printf(const char *, ...);

#endif