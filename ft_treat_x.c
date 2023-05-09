/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:27:46 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/09 17:38:25 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_x(va_list args, char c, char *base, int *count)
{
	int	x;

	if (c == 'x')
	{
		x = va_arg(args, int);
		ft_putnbr_base_x(x, base, count);
	}
}

void	ft_treat_xup(va_list args, char c, char *base_xup, int *count)
{
	unsigned int	xup;

	if (c == 'X')
	{
		xup = va_arg(args, unsigned int);
		ft_putnbr_base_x(xup, base_xup, count);
	}
}
