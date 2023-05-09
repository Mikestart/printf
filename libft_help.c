/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:22:03 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/09 16:25:21 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr((nb / 10), count);
		ft_putnbr((nb % 10), count);
	}
	else
	{	
		ft_putchar(nb + '0', count);
	}
}

void	ft_putnbr_base_p(unsigned long p, char *base, int *count)
{
	if (p >= 0 && p < 16)
		ft_putchar(base[p], count);
	if (p >= 16)
	{
		ft_putnbr_base_p((p / 16), base, count);
		ft_putchar(base[p % 16], count);
	}
}

void	ft_putnbr_base_x(unsigned int x, char *base, int *count)
{
	if (x >= 0 && x < 16)
		ft_putchar(base[x], count);
	if (x >= 16)
	{
		ft_putnbr_base_x((x / 16), base, count);
		ft_putchar(base[x % 16], count);
	}
}

void	ft_unsigned_putnbr(unsigned int u, int *count)
{
	int	i;

	i = 0;
	if (u > 9)
	{
		ft_unsigned_putnbr((u / 10), count);
		ft_unsigned_putnbr((u % 10), count);
	}
	else
		ft_putchar(u + '0', count);
}
