/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabr <ysabr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:49:42 by ysabr             #+#    #+#             */
/*   Updated: 2022/11/12 12:27:24 by ysabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_len_hex(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_putnbrhex(unsigned long nb)
{
	int		i;
	char	*s;

	s = "0123456789abcdef";
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (nb > 15)
		ft_putnbrhex (nb / 16);
	ft_putchar (s[nb % 16]);
	i = print_len_hex (nb);
	return (i);
}
