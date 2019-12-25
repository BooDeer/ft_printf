/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:11:47 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/25 18:01:13 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int     main()
{
    ft_printf("ultimate2 %*d\n", 1, 5000);
	   printf("ultimate2 %*d\n", 1, 5000);
}   