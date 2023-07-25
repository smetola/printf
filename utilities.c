/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:55:35 by sanmetol          #+#    #+#             */
/*   Updated: 2023/07/25 14:20:54 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	if (write(1, &c, 1) == -1)
		*count = -1;
	else
		(*count)++;
}

void	ft_putstr(char *s, int *count)
{
	int		i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-', count);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
		ft_putchar(n + '0', count);
}

void	ptrhexa(unsigned long int n, int *count)
{
	char		*hex_base;
	int			i;
	char		hex[16];

	hex_base = "0123456789abcdef";
	i = 0;
	ft_putstr("0x", count);
	if (n == 0)
		ft_putchar('0', count);
	else
	{
		while (n > 0)
		{
			hex[i] = hex_base[n % 16];
			n = n / 16;
			i++;
		}
		i--;
		while (i >= 0)
		{
			ft_putchar(hex[i], count);
			i--;
		}
	}
}

void	ft_puthexa(unsigned int n, char x_or_X, int *count)
{
	char	*hex;

	if (x_or_X == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n > 16)
	{
		ft_puthexa(n / 16, x_or_X, count);
		ft_puthexa(n % 16, x_or_X, count);
	}
	else
		ft_putchar(hex[n], count);
}
