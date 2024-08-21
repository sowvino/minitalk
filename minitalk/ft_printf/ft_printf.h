/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-18 10:21:40 by selango           #+#    #+#             */
/*   Updated: 2024-06-18 10:21:40 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_print_str(char *str);
int		ft_print_char(int c);
int		ft_print_digit(long n, int base, int is_upper);
int		ft_print_pointer(void *ptr);
int		ft_printf(const char *format, ...);
int		print_format(char specifier, va_list ap);

#endif