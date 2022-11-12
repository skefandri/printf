/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabr <ysabr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:03:14 by ysabr             #+#    #+#             */
/*   Updated: 2022/11/12 17:16:32 by ysabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_number(int num)
{
	char	*nbr;
	int		print_len;

	print_len = 0;
	nbr = ft_itoa(num);
	print_len += ft_putstr(nbr);
	free(nbr);
	return (print_len);
}

static int	print_len_unse(unsigned int num)
{
	char	*nbr;
	int		print_len;

	print_len = 0;
	nbr = ft_itoaunsigned(num);
	print_len += ft_putstr(nbr);
	free(nbr);
	return (print_len);
}

static int	ft_check(const char s, va_list ptr)
{
	int	print_len;

	print_len = 0;
	if (s == '%')
		print_len += ft_putchar('%');
	else if (s == 'd' || s == 'i')
		print_len += print_number(va_arg(ptr, int));
	else if (s == 'c')
		print_len += ft_putchar(va_arg(ptr, int));
	else if (s == 's')
		print_len += ft_putstr(va_arg(ptr, char *));
	else if (s == 'p')
	{
		ft_putstr ("0x");
		print_len += ft_putnbrhex (va_arg(ptr, unsigned long)) + 2;
	}
	else if (s == 'u')
		print_len += print_len_unse(va_arg(ptr, unsigned int));
	else if (s == 'x')
		print_len += ft_putnbrhex(va_arg(ptr, unsigned int));
	else if (s == 'X')
		print_len += ft_putnbrhexx(va_arg(ptr, unsigned int));
	else
		print_len += ft_putchar(s);
	return (print_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		c;

	va_start(ptr, s);
	c = 0;
	while (*s)
	{
		if (*s == '%' )
		{
			s++;
			c += ft_check(*s, ptr);
		}
		else
			c += ft_putchar(*s);
		s++;
	}
	va_end (ptr);
	return (c);
}
