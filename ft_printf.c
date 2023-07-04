/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:53:09 by sanmetol          #+#    #+#             */
/*   Updated: 2023/07/04 15:49:23 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_arg(char s, va_list args_l, int *count)
{
	if (s == 'c')
		ft_putchar(va_arg(args_l, int), count);
	else if (s == 's')
		ft_putstr(va_arg(args_l, char *), count);
	else if (s == 'p')
		ptrhexa(va_arg(args_l, unsigned long int), count);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args_l, int), count);
	else if (s == 'u')
	{
		if (va_arg(args_l, unsigned int) > 2147483647)
		{
			unsigned int u = 4294967196 - args_l;
			ft_putstr(ft_itoa(u), count);
		}
		else
			ft_putnbr(va_arg(args_l, unsigned int), count);
	}
	else if (s == 'x' || s == 'X')
		ft_puthexa(va_arg(args_l, int), s, count);
	else if (s == '%')
		ft_putchar('%', count);
}

int	ft_printf(char const *s, ...)
{
	va_list	args_l;
	int		i;
	int		count;

	count = 0;
	va_start(args_l, s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i], &count);
		else if (s[i] == '%')
		{
			i++;
			ft_va_arg(s[i], args_l, &count);
		}
		i++;
	}
	va_end(args_l);
	return (count);
}

int	main(void)
{
	int				n = 42;
	unsigned int	u = -100;
	char			c = 'z';
	char 			*s = "paola";
	void			*p = &n;
	int				output;
	int				outputZERO;

	outputZERO = ft_printf("\n%c, %s, %p, %d, %i, %u,"
		" %x, %X, %%", c, s, p, n, n, u, n, n);
	output     =    printf("\n%c, %s, %p, %d, %i, %u,"
		" %x, %X, %%", c, s, p, n, n, u, n, n);
	printf("\n%d\n%d\n", outputZERO, output);
}

//gcc ft_printf.c utilities.c && ./a.out
//gcc ft_printf.c utilities.c ft_itoa.c && ./a.out