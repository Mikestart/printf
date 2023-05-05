/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:43:22 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/05 17:45:45 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

char		*ft_itoa(int n);
static int	size(long n);
int			ft_printf(const char *str, ...);
void	ft_treat_general(va_list args, char c);
void	ft_putchar(char c);
void ft_treat_c(va_list args, char c);
void ft_treat_s(va_list args, char c);
void ft_treat_d(va_list args, char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
void ft_putnbr_16 (void *p);
void	ft_treat_p(va_list args, char c);

#endif