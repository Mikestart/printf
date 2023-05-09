/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:43:22 by mtoledan          #+#    #+#             */
/*   Updated: 2023/05/09 17:38:37 by mtoledan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_treat_general(va_list args, char c, int *count);
void	ft_putchar(char c, int *count);
void	ft_treat_c(va_list args, char c, int *count);
void	ft_treat_s(va_list args, char c, int *count);
void	ft_treat_d(va_list args, char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putnbr_base_p(unsigned long p, char *base, int *count);
void	ft_putnbr_base_x(unsigned int x, char *base, int *count);
void	ft_treat_p(va_list args, char c, char *base, int *count);
void	ft_unsigned_putnbr(unsigned int u, int *count);
void	ft_treat_u(va_list args, char c, int *count);
void	ft_treat_x(va_list args, char c, char *base, int *count);
void	ft_treat_xup(va_list args, char c, char *base_X, int *count);

#endif