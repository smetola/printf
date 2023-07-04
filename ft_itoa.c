/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:51:28 by sanmetol          #+#    #+#             */
/*   Updated: 2023/07/04 15:47:24 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	if (nbr <= 0)
	{
		count = 1;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}

char	*ft_itoa(unsigned int n)
{
	int				digits;
	int				neg;
	char			*str;
	unsigned int	nbr;

	nbr = n;
	digits = count_digits(nbr);
	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		nbr = -nbr;
	}
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[digits] = '\0';
	while (digits--)
	{
		str[digits] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

/* int  main(void)
{
  printf("%s\n", ft_itoa(-2147483648));
} */