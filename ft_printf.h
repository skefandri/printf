/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabr <ysabr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:07:05 by ysabr             #+#    #+#             */
/*   Updated: 2022/11/12 13:07:34 by ysabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int			ft_printf(const char *s, ...);
int			ft_putstr(char *str);
int			ft_putnbrhex(unsigned long nb);
int			ft_putchar(char c);
char		*ft_itoa(int n);
char		*ft_itoaunsigned(unsigned int n);
int			ft_putnbrhexx(unsigned int nb);
#endif
