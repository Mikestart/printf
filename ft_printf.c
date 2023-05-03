/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:08:33 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/03 16:47:58 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_find_charset(char c)
{
	int i;
	char *set;

	i = 0;
	set = "csdiuxX%";
	while (set[i])
	{
		if (set[i] == c)
		{
			return(1);
		}
		i++;
	}
	return(0);
}
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list args;

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
		ft_treat_c(args, c);
	/*if (c = 's')
		appel de ma fonction qui traite s
	etc etc */
}

void ft_treat_c(va_list args, char c)
{
	char cb;

	cb = 0;

	if (c == '%')
		ft_putchar('%');
	if (c == 'c')
	{
		cb = va_arg(args, int);
		ft_putchar((char)cb);
	}
}
int	main(void)
{
	char c;
	c = 'l';
	// printf("camille%%c\n");
	ft_printf("Mike %c");
	// ft_browse_str("lol%%%%\n");
	//print_c(6, 'A', 'B', 'C', 'D', 'E');
	//printf("Exemple de printf : %s\n");
}

// int	ft_printf(const char *str, ...)
// {
// 	int		i;
// 	va_list args;

// 	va_start(args, str);

// 	va_arg(args, int);
// 	i = 0;

// 	va_end(args);
// }

// void	print_c(int nb, ...)
// {
// 	va_list	args;
// 	int		i;
// 	char	c;

// 	i = 0;
// 	va_start(args, nb);
// 	while (i < nb)
// 	{
// 		c = va_arg(args, int);
// 		printf("%c ", c);
// 		i++;
// 	}
// 	printf("\n");
// 	va_end(args);
// }
// void ft_print_str(char* str)
// {
// 	int	i;
// 	i = 0;

// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }
