/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:08:33 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/05 18:05:21 by mtoledan         ###   ########.fr       */
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
		}
		i++;
	}
	va_end(args);
	return (i);
}

void	ft_treat_general(va_list args, char c)
{
	if (c == 'c')
		ft_treat_c(args, c);
	if (c == 's')
		ft_treat_s(args, c);
	if (c == 'd' || c == 'i')
		ft_treat_d(args, c);
	if (c == 'p')
		ft_treat_p(args, c);
}


int	main(void)
{
	//printf("%d\n", 200);
	ft_printf("%p", "sftrgyjtfjjtyj");
	// ft_browse_str("lol%%%%\n");
	//print_c(6, 'A', 'B', 'C', 'D', 'E');
	//printf("Exemple de printf : %s\n");
}