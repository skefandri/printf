/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrHEXX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabr <ysabr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:40:20 by ysabr             #+#    #+#             */
/*   Updated: 2022/11/12 13:09:52 by ysabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_len_hex(unsigned int nb)
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

int	ft_putnbrhexx(unsigned int nb)
{
	int		i;
	char	*s;

	s = "0123456789ABCDEF";
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (nb > 15)
		ft_putnbrhexx (nb / 16);
	ft_putchar (s[nb % 16]);
	i = print_len_hex(nb);
	return (i);
}
