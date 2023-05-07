/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:43:22 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/07 16:55:04 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

//char		*ft_itoa(int n);
//static int	ft_size(long n);
int			ft_printf(const char *str, ...);
void	ft_treat_general(va_list args, char c);
void	ft_putchar(char c);
void ft_treat_c(va_list args, char c);
void ft_treat_s(va_list args, char c);
void ft_treat_d(va_list args, char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
//void ft_putnbr_16 (void *p);
void	ft_putnbr_base_p(unsigned long p, char *base);
void	ft_putnbr_base_x(int x, char *base);
void	ft_treat_p(va_list args, char c, char *base);
void	ft_unsigned_putnbr(unsigned int u);
void	ft_treat_u(va_list args, char c);
void	ft_treat_x(va_list args, char c, char *base);
char	*ft_strupcase(char *str);
void	ft_treat_X(va_list args, char c, char *base_X);

#endif