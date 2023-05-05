/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:31:05 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/05 17:59:29 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_s(va_list args, char c)
{
	char	*ct;

	if (c == '%')
		ft_putchar('%');
	if (c == 's')
	{
		ct = va_arg(args, char *);
		ft_putstr((char *)ct);
	}
}

void	ft_treat_c(va_list args, char c)
{
	char	cb;

	cb = 0;
	if (c == '%')
		ft_putchar('%');
	if (c == 'c')
	{
		cb = va_arg(args, int);
		ft_putchar((char)cb);
	}
}

void	ft_treat_d(va_list args, char c)
{
	int	n;

	n = 0;
	if (c == '%')
		ft_putchar('%');
	if (c == 'd' || c == 'i')
	{
		n = va_arg(args, int);
		ft_putnbr(n);
	}
}


void ft_putnbr_16 (void *p)
{
	unsigned long	n;
	int				i;
	int				digit;
	char			buffer[16];
	
	n = (unsigned long)p;
	i = 0;
	digit = 0;
	buffer[i] = '0';
	i = 15;
	while (n > 0)
	{
		digit = n % 16;
		if (digit < 10)
		{
			buffer[i] = '0' + digit;
		}
		else
		{
			buffer[i] = 'a' + digit - 10;
		}
		i--;
		n /= 16;
	}
	ft_putstr("0x");
	ft_putstr(buffer + i + 1);
}

void	ft_treat_p(va_list args, char c)
{
	void *u;
	if (c == '%')
		ft_putchar('%');
	if (c == 'p')
	{
		u = va_arg(args, void *);
		ft_putnbr_16(u);
	}
}
