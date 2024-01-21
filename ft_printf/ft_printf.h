/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:33:55 by ahaarij           #+#    #+#             */
/*   Updated: 2023/12/10 10:52:48 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

int	ft_printchar(int c);
int	ft_printhex(unsigned int n, int x);
int	ft_printnbr(int number);
int	ft_printstr(char *str);
int	ft_printuint(unsigned int c);
int	ft_printptr(void *ptr);
int	ft_printf(const char *input, ...);

#endif