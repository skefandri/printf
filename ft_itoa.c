/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabr <ysabr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:42:59 by ysabr             #+#    #+#             */
/*   Updated: 2022/11/12 17:16:22 by ysabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	convert_count(char *str, long int n)
{
	int	index;
	int	count;

	count = count_digit(n);
	index = 0;
	if (n < 0)
	{
		n *= -1;
		str[index] = '-';
		index++;
	}
	str[count] = '\0';
	while (index < count--)
	{
		str[count] = n % 10 + 48;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = count_digit ((long int)n);
	str = malloc ((sizeof(char) * len) + 1);
	if (!str)
		return (NULL);
	convert_count (str, (long int) n);
	return (str);
}
