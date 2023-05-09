/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:08:33 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/09 17:38:59 by mtoledan         ###   ########.fr       */
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

void	ft_treat_general(va_list args, char c, int *count)
{
	char	*base;
	char	*base_xup;

	base = "0123456789abcdef";
	base_xup = "0123456789ABCDEF";
	if (c == 'c' || c == '%')
		ft_treat_c(args, c, count);
	if (c == 's')
		ft_treat_s(args, c, count);
	if (c == 'd' || c == 'i')
		ft_treat_d(args, c, count);
	if (c == 'p')
		ft_treat_p(args, c, base, count);
	if (c == 'u')
		ft_treat_u(args, c, count);
	if (c == 'x')
		ft_treat_x(args, c, base, count);
	if (c == 'X')
		ft_treat_xup(args, c, base_xup, count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &count);
		else
		{	
			i++;
			if (ft_find_charset(str[i]) == 1)
			{
				ft_treat_general(args, str[i], &count);
			}
			else
				return (0);
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*int	main(void)
{
	//char base[70] = "0123456789abcdef";
	//printf("%d\n", 200);
	//ft_printf("%s %d %p", "Mickael", 1, nb);
	int result;
	result = ft_printf("%s %s\n", "abc", "abc");
	printf("%s", NULL);
	// ft_browse_str("lol%%%%\n");
	//print_c(6, 'A', 'B', 'C', 'D', 'E');
	//printf("Exemple de printf : %s\n");
}*/