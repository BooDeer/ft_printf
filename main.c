#include "srcs/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main()
{
	int a, b;

	a = ft_printf("%04.x\n", 100);
	b =    printf("%04.x\n", 100);

	printf("%d\n%d\n", a, b);
}