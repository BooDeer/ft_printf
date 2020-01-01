/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:11:47 by hboudhir          #+#    #+#             */
/*   Updated: 2020/01/01 18:38:20 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int     main()
{
    int a = 0,b;

	
    a = ft_printf("Bla bla %*x\n", -15, 0);
    b =    printf("Bla bla %*x\n", -15, 0);
	
    printf("%d\n%d\n", a,b);
}