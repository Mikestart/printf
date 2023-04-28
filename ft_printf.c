/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:08:33 by mtoledan          #+#    #+#             */
/*   Updated: 2023/04/28 14:34:26 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
//#include "ft_printf.h"

// int	ft_printf(const char *str, ...)
// {
// 	int		i;
// 	va_list args;

// 	va_start(args, str);

// 	va_arg(args, int);
// 	i = 0;

// 	va_end(args);
// }

void	print_c(int nb, ...)
{
	va_list	args;
	int		i;
	char	c;

	i = 0;
	va_start(args, nb);
	while (i < nb)
	{
		c = (char)va_arg(args, int);
		printf("%c ", c);
		i++;
	}
	printf("\n");
	va_end(args);
}
void ft_print_str(char* str)
{
	int	i;
	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
void ft_browse_str(char* str)
{
	int	i;
	i = 0;

	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}
int	main(void)
{
	printf("camille%%c\n");
	ft_print_str("camille %c\n");
	ft_browse_str("lol%%%%\n");
	//print_c(5, 'A', 'B', 'C', 'D', 'E');
}