/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:37:43 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/18 17:43:16 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

void		ft_putstr(char *c);
void		ft_putchar(char c);
char		*ft_test(char c);
char		*ft_hexconv(unsigned int	c);
int			skip_spefix(char c, char *set);
void		get_ls(char	*str, t_list **root);
int		    ft_printf(const char *, ...);
void		ft_c_specifier(va_list args, t_list *node);
void		ft_s_specifier(va_list args, t_list *node);
void		ft_d_specifier(va_list args, t_list *node);
char		*ft_bigx_specifier(va_list args, t_list *node);
void	    ft_x_specifier(va_list args, t_list *node);
void	    ft_u_specifier(va_list args, t_list *node);
void	    ft_p_specifier(va_list args, t_list *node);
char	    *ft_strrev(char *str);
void		ft_percent_specifier(va_list args, t_list *node);

#endif