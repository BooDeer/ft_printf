/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:37:43 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/04 06:57:57 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_printf
{
	char	*string;
	char	*precision;
	char	*width;
	int		d;
	char	flag;
}				t_printf;

typedef struct	s_indexes
{
	size_t	i;
	size_t	start;
	size_t	skipcnv;
}				t_index;

void			ft_putstr(char *c);
void			ft_putchar(char c);
char			*ft_test(char c);
void			ft_hexconv(unsigned int c, t_printf *a);
int				skip_spefix(char c, char *set);
void			get_ls(char	*str, t_list **root);
int				ft_printf(const char *str, ...);
void			ft_c_specifier(va_list args, t_list *node);
void			ft_s_specifier(va_list args, t_list *node);
void			ft_d_specifier(va_list args, t_list *node);
char			*ft_bigx_specifier(va_list args, t_list *node);
void			ft_x_specifier(va_list args, t_list *node);
void			ft_u_specifier(va_list args, t_list *node);
int				precision_exist(t_list *node, int i);
void			ft_p_specifier(va_list args, t_list *node);
char			*ft_strrev(char *str);
t_printf		*initializing(void);
char			*ft_hexconv1(size_t c);
void			deletinglist(t_list **root);
int				precision_exist(t_list *node, int i);
void			ft_percent_specifier(va_list args, t_list *node);
int				ft_bigx01(t_printf *a, t_list *node, va_list args);
int				ft_p_speficier01(t_printf *p, va_list args, t_list *node,
int i);
void			ft_p_speficier02(t_printf *p, va_list args, t_list *node,
int i);
int				ft_bigx02(t_printf *a, t_list *node, va_list args, int i);
int				ft_d_specifier01(t_printf *d, va_list args, t_list *node,
int i);
void			ft_d_specifier02(t_printf *d, va_list args, t_list *node,
int i);
void			ft_d_specifier04(t_printf *d, int len);
void			ft_d_specifier05(t_printf *d, int len);
int				ft_u_speficier01(t_printf *u, va_list args, t_list *node,
int i);
void			ft_u_speficier02(t_printf *u, va_list args, t_list *node,
int i);
void			ft_u_speficier031(t_printf *u, int len);
void			ft_u_speficier03(t_printf *u, int len);
void			ft_u_speficier041(t_printf *u, int len);
char			*print_number(char *number, size_t len, unsigned int nb);
void			ft_u_speficier04(t_printf *u, int len);
int				ft_count(unsigned int n);
char			*ft_itoa1(unsigned int n);
unsigned int	ft_atoi1(const char *c);
int				ft_counter(int n);
void			ft_u_speficier04(t_printf *u, int len);
#endif
