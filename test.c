/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:49:59 by hboudhir          #+#    #+#             */
/*   Updated: 2019/12/02 15:19:02 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int c, ...)
{
	va_list lst;
	int		i, sum = 0;
	i = 0;
	va_start(lst, c);
	
	while (i++ < c)
	{
		sum += va_arg(lst, int);
	}
	return (sum);
}

int main()
{
	int summ = sum(4, 1, 2, 3, 4);

	printf("%d\n", summ);
}