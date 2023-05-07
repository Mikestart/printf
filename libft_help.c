/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:22:03 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/07 16:57:09 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ft_size(long n)
// {
// 	int	len;

// 	len = 0;
// 	if (n == 0)
// 		return (1);
// 	if (n < 0)
// 	{
// 		n = n * -1;
// 		len++;
// 	}
// 	while (n > 0)
// 	{
// 		n = n / 10;
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	long	nb;
// 	int		i;

// 	nb = (long) n;
// 	i = ft_size(nb);
// 	str = malloc((i + 1) * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	str[i--] = '\0';
// 	if (nb < 0)
// 	{
// 		str[0] = '-';
// 		nb = nb * -1;
// 	}
// 	while ((n < 0 && i > 0) || (n >= 0 && i >= 0))
// 	{
// 		str[i] = '0' + (nb % 10);
// 		nb = nb / 10;
// 		i--;
// 	}
// 	return (str);
// }
void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{	
		ft_putchar(nb + '0');
	}
}

void	ft_putnbr_base_p(unsigned long p, char *base)
{
	if (p >= 0 && p < 16)
		ft_putchar(base[p]);
	if (p >= 16)
	{
		ft_putnbr_base_p((p / 16), base);
		ft_putchar(base[p % 16]);
	}
}

void	ft_putnbr_base_x(int x, char *base)
{
	if (x >= 0 && x < 16)
		ft_putchar(base[x]);
	if (x >= 16)
	{
		ft_putnbr_base_x((x / 16), base);
		ft_putchar(base[x % 16]);
	}
}

void	ft_unsigned_putnbr(unsigned int u)
{
	int	i;

	i = 0;
	if (u > 9)
	{
		ft_unsigned_putnbr(u / 10);
		ft_unsigned_putnbr(u % 10);
	}
	else
		ft_putchar(u + '0');
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
// int main (void)
// { 
// 	char string[70] = "shjrhporjtdhdt7r"; 
// 	printf("%s", ft_strupcase(string));
// }