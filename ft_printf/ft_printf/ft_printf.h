/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 07:26:54 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 07:26:55 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putstr(char *s, int *len);
void	ft_adresse(void *ad, int *len);
void	ft_numberh(unsigned int n, char c, int *len);
void	ft_putnbr_uns(unsigned int n, int *len);
int		ft_printf(const char *c, ...);

#endif
