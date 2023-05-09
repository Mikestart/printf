/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:22:33 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/09 16:22:40 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	*count = *count + 1;
	write (1, &c, 1);
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], count);
		i++;
	}
}
