/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:08:33 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/07 18:19:42 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_charset(char c)
{
	int		i;
	char	*set;

	i = 0;
	set = "cspdiuxX%";
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}


void	ft_treat_general(va_list args, char c)
{
	char *base;
	char *base_X = "0123456789ABCDEF";

	base = "0123456789abcdef";
	//base_X = ft_strupcase(base);

	if (c == 'c' ||c =='%')
		ft_treat_c(args, c);
	if (c == 's')
		ft_treat_s(args, c);
	if (c == 'd' || c == 'i')
		ft_treat_d(args, c);
	if (c == 'p')
		ft_treat_p(args, c, base);
	if (c == 'u')
		ft_treat_u(args, c);
	if (c == 'x')
		ft_treat_x(args, c, base);
	if (c == 'X')
		ft_treat_X(args, c, base_X);
	//if (c == '%')
	//	ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{	
			i++;
			if (ft_find_charset(str[i]) == 1)
			{
				ft_treat_general(args, str[i]);
			}
			else
				return (0);
		}
		i++;
	}
	va_end(args);
	return (i);
}
int	main(void)
{
	void * nb;
	nb = 25;
	//char base[70] = "0123456789abcdef";
	//printf("%d\n", 200);
	//ft_printf("%s %d %p", "Mickael", 1, nb);
	printf("%s %d %p", "Mickael", 1, nb);
	// ft_browse_str("lol%%%%\n");
	//print_c(6, 'A', 'B', 'C', 'D', 'E');
	//printf("Exemple de printf : %s\n");
}