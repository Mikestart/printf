/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:31:05 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/09 17:41:48 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_s(va_list args, char c, int *count)
{
	char	*ct;

	ct = va_arg(args, char *);
	if (c == 's')
	{
		if (ct == NULL)
			ft_putstr("(null)", count);
		else
			ft_putstr((char *)ct, count);
	}
}

void	ft_treat_c(va_list args, char c, int *count)
{
	char	cb;

	cb = 0;
	if (c == '%')
		ft_putchar('%', count);
	if (c == 'c')
	{
		cb = va_arg(args, int);
		ft_putchar((char)cb, count);
	}
}

void	ft_treat_d(va_list args, char c, int *count)
{
	int	n;

	n = 0;
	if (c == 'd' || c == 'i')
	{
		n = va_arg(args, int);
		ft_putnbr(n, count);
	}
}

void	ft_treat_p(va_list args, char c, char *base, int *count)
{
	void			*p;
	unsigned long	n;

	p = NULL;
	n = (unsigned long)p;
	if (c == 'p')
	{
		n = va_arg(args, unsigned long);
		ft_putstr("0x", count);
		ft_putnbr_base_p(n, base, count);
	}
}

void	ft_treat_u(va_list args, char c, int *count)
{
	unsigned int	u;

	u = 0;
	if (c == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_unsigned_putnbr(u, count);
	}
}

// void ft_putnbr_16b (void *p)
// {
// 	unsigned long	n;
// 	int				i;
// 	int				digit;
// 	char			buffer[16];
// 	n = (unsigned long)p;
// 	i = 0;
// 	digit = 0;
// 	buffer[i] = '0';
// 	i = 15;
// 	while (n > 0)
// 	{
// 		digit = n % 16;
// 		if (digit < 10)
// 		{
// 			buffer[i] = '0' + digit;
// 		}
// 		else
// 		{
// 			buffer[i] = 'a' + digit - 10;
// 		}
// 		i--;
// 		n /= 16;
// 	}
// 	ft_putstr(buffer + i + 1);
// }